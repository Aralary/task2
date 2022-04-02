// Copyright 2022 <Aralary>
#include "headers/th_m_transpose.h"

void *th_transpose(void *thread_data) {
    th_data *data = (th_data *) thread_data;
    for (size_t i = data->th_id; i < data->rows; i += data->th_count) {
        for (size_t j = 0; j < data->columns; ++j) {
            data->res[i][j] =
                    data->matrix[data->rows - 1 - i][data->columns - 1 - j];
        }
    }
}

int **multi_thread_transpose
        (int **matrix, int add_threads_count, size_t rows, size_t columns) {
    int **res = malloc(rows * sizeof(int *));
    for (size_t i = 0; i < rows; ++i) {
        res[i] = malloc(columns * sizeof(int));
    }
    pthread_t *threads =
            (pthread_t *) malloc(add_threads_count * sizeof(pthread_t));
    th_data *thData = (th_data *) malloc(add_threads_count * sizeof(th_data));
    for (size_t i = 1; i <= add_threads_count; ++i) {
        thData[i - 1].columns = columns;
        thData[i - 1].rows = rows;
        thData[i - 1].th_count = add_threads_count + 1;
        thData[i - 1].th_id = i;
        thData[i - 1].res = res;
        thData[i - 1].matrix = matrix;
        pthread_create(&threads[i - 1], NULL, th_transpose, &thData[i - 1]);
    }
    th_data main_th_data;
    main_th_data.columns = columns;
    main_th_data.rows = rows;
    main_th_data.th_count = add_threads_count + 1;
    main_th_data.th_id = 0;
    main_th_data.res = res;
    main_th_data.matrix = matrix;
    th_transpose(&main_th_data);

    for (size_t i = 0; i < add_threads_count; ++i) {
        pthread_join(threads[i], NULL);
    }

    free(threads);
    free(thData);
    return res;
}

void matrix_cleaner(int **matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        free(matrix[i]);
    }
    free(matrix);
}

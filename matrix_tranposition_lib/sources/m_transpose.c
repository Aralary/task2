#include "m_transpose.h"

int **transpose(int **matrix, size_t rows, size_t columns) {
    int **m2 = malloc(rows * sizeof(int *));
    for (size_t i = 0; i < rows; ++i) {
        m2[i] = malloc(columns * sizeof(int));
        for (size_t j = 0; j < columns; ++j) {
            m2[i][j] = matrix[rows - 1 - i][columns - 1 - j];
        }
    }
    return m2;
}

void print_matrix(int **matrix, size_t rows, size_t columns) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


//program arguments : path_to_file_with_matrix , count_of_threads
void prepare_matrix_file(char path[],size_t rows,size_t columns) {
    FILE *file;
    if ((file = fopen(path, "w")) == NULL) {
        printf("Не удалось открыть файл");
        getchar();
        return;
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            int a = (i * j + 5 * (i + j)) % 23423;
            fprintf(file, "%d ", a);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int **read_from_file(char path[],size_t rows,size_t columns) {
    FILE *file;
    if ((file = fopen(path, "r+")) == NULL) {
        printf("Не удалось открыть файл");
        getchar();
        return NULL;
    }
    int **res = malloc(rows * sizeof(int *));
    for (size_t i = 0; i < rows; ++i) {
        res[i] = malloc(columns * sizeof(int));
        for (size_t j = 0; j < columns; ++j) {
            fscanf(file, "%d", &res[i][j]);
        }
    }
    fclose(file);
    return res;
}
//Copyright 2022 <Aralary>
#ifndef TASK2_TH_M_TRANSPOSE_H

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define TASK2_TH_M_TRANSPOSE_H

typedef struct {
    int **matrix;
    int **res;
    size_t rows;
    size_t columns;
    size_t th_id;
    int th_count;
} th_data;

void *th_transpose(void *thread_data);

int **multi_thread_transpose(int **matrix, int add_threads_count, size_t rows, size_t columns);

void matrix_cleaner(int **matrix, size_t rows);

#endif // TASK2_TH_M_TRANSPOSE_H

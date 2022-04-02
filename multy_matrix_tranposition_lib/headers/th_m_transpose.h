// Copyright 2022 <Aralary>
#ifndef MULTY_MATRIX_TRANPOSITION_LIB_HEADERS_TH_M_TRANSPOSE_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define MULTY_MATRIX_TRANPOSITION_LIB_HEADERS_TH_M_TRANSPOSE_H_

typedef struct {
    int **matrix;
    int **res;
    size_t rows;
    size_t columns;
    size_t th_id;
    int th_count;
} th_data;

void *th_transpose(void *thread_data);

int **multi_thread_transpose
        (int **matrix, int add_threads_count, size_t rows, size_t columns);

void matrix_cleaner(int **matrix, size_t rows);

#endif  // MULTY_MATRIX_TRANPOSITION_LIB_HEADERS_TH_M_TRANSPOSE_H_

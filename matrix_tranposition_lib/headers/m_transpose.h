// Copyright 2022 <Aralary>
#ifndef MATRIX_TRANPOSITION_LIB_HEADERS_M_TRANSPOSE_H_

#include <stdlib.h>
#include <stdio.h>

#define MATRIX_TRANPOSITION_LIB_HEADERS_M_TRANSPOSE_H_

int **transpose(int **matrix, size_t rows, size_t columns);

void print_matrix(int **matrix, size_t rows, size_t columns);

int **read_from_file(char path[], size_t rows, size_t columns);

void prepare_matrix_file(char path[], size_t rows, size_t columns);

#endif  // MATRIX_TRANPOSITION_LIB_HEADERS_M_TRANSPOSE_H_

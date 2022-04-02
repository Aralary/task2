//Copyright 2022 <Aralary>
#ifndef TASK2_M_TRANPOSE_H

#include <stdlib.h>
#include <stdio.h>

#define TASK2_M_TRANPOSE_H

int **transpose(int **matrix, size_t rows, size_t columns);

void print_matrix(int **matrix, size_t rows, size_t columns);

int **read_from_file(char path[], size_t rows, size_t columns);

void prepare_matrix_file(char path[], size_t rows, size_t columns);

#endif // TASK2_M_TRANPOSE_H

// Copyright 2022 <Aralary>
#include <gtest/gtest.h>

extern "C" {
#include "headers/th_m_transpose.h"
#include "headers/m_transpose.h"
}


TEST(matrix_transpose, test1) {
    size_t rows = 20;
    size_t columns = 10;
    char path[] = "./test_matrix.txt";
    prepare_matrix_file(path, rows, columns);
    int **matrix = read_from_file(path, rows, columns);
    EXPECT_EQ(matrix[0][0], 0);

    int **transposed = transpose(matrix, rows, columns);
    EXPECT_EQ(transposed[0][0], 311);

    EXPECT_EQ(transposed[rows - 1][0], matrix[0][columns - 1]);
    matrix_cleaner(matrix, rows);
    matrix_cleaner(transposed, rows);
}

TEST(matrix_transpose, test2) {
    int threads_count = 5;
    size_t rows = 20;
    size_t columns = 10;
    char path[] = "./test_matrix.txt";
    prepare_matrix_file(path, rows, columns);
    int **matrix = read_from_file(path, rows, columns);
    EXPECT_EQ(matrix[0][0], 0);

    int **transposed1 = transpose(matrix, rows, columns);
    EXPECT_EQ(transposed1[0][0], 311);

    int **transposed2 =
            multi_thread_transpose(matrix, threads_count, rows, columns);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            EXPECT_EQ(transposed1[i][j], transposed2[i][j]);
        }
    }
    EXPECT_EQ(transposed1[rows - 1][0], matrix[0][columns - 1]);
    matrix_cleaner(matrix, rows);
    matrix_cleaner(transposed1, rows);
    matrix_cleaner(transposed2, rows);
}

#include <stdio.h>
#include <sys/sysinfo.h>
#include <time.h>

#include "m_transpose.h"
#include "th_m_transpose.h"

#define ROWS 10000
#define COLUMNS 5000

int main(int argc, char *argv[]) {

    if (argc < 3) {
        return 0;
    }
    prepare_matrix_file(argv[1], ROWS, COLUMNS);
    int **matrix = read_from_file(argv[1], ROWS, COLUMNS);

    int add_threads_count = atoi(argv[2]);
    if (add_threads_count < 1) {
        return 0;
    }
    int max_th = get_nprocs();
    if (add_threads_count >= max_th) {
        add_threads_count = max_th - 1;
    } else {
        add_threads_count -= 1;
    }

    clock_t start, end;
    if (add_threads_count > 0) {
        start = clock();
        int **res = multi_thread_transpose(matrix, add_threads_count, ROWS, COLUMNS);
        end = clock();
        printf("Transpose duration with %d threads is %.6lf seconds\n", add_threads_count + 1,
               (double) (end - start) / (double) (CLOCKS_PER_SEC));
        matrix_cleaner(res, ROWS);
    } else {
        //one_thread_transpose
        start = clock();
        int **res = transpose(matrix, ROWS, COLUMNS);
        end = clock();
        matrix_cleaner(res, ROWS);

        printf("Transpose duration with %d threads is %.6lf seconds\n", 1,
               (double) (end - start) / (double) (CLOCKS_PER_SEC));
    }
    matrix_cleaner(matrix, ROWS);
    return 0;
}

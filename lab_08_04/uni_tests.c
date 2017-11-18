#include <stdio.h>
#include <math.h>
#include <string.h>

#include "matrix.h"
#include "constant.h"

#define EPS 1E-5
#define func __func__

void scan_tests(void);
void determinant_tests(void);
void addition_matrix_tests(void);
void multiply_matrix_tests(void);

int main(void)
{
    scan_tests();
    determinant_tests();
    addition_matrix_tests();
    multiply_matrix_tests();

    return OK;
}

void scan_tests(void)
{
    int ok_count = 0;

    // 1 test
    {
        int res_row = 3, res_col = 3;
        FILE * file = fopen("in_1.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if ((res_row == matrix->rows) && (res_col == matrix->columns))
        {
            ok_count++;
        }
        free_matrix(matrix);
        fclose(file);
    }

    // 2 test
    {
        int res_row = 3, res_col = 2;
        FILE * file = fopen("in_2.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if ((res_row == matrix->rows) && (res_col == matrix->columns))
        {
            ok_count++;
        }
        free_matrix(matrix);
        fclose(file);
    }

    // 3 test
    {
        FILE * file = fopen("in_3.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if (!matrix)
        {
            ok_count++;
        }
        fclose(file);
    }

    // 4 test
    {
        int res_row = 3, res_col = 3;
        FILE * file = fopen("in_4.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if ((res_row == matrix->rows) && (res_col == matrix->columns))
        {
            ok_count++;
        }
        free_matrix(matrix);
        fclose(file);
    }

    // 5 test
    {
        FILE * file = fopen("in_5.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if (!matrix)
        {
            ok_count++;
        }
        fclose(file);
    }

    // 6 test
    {
        FILE * file = fopen("in_8.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if (!matrix)
        {
            ok_count++;
        }
        fclose(file);
    }

    // 7 test
    {
        FILE * file = fopen("in_9.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if (!matrix)
        {
            ok_count++;
        }
        fclose(file);
    }

    // 8 test
    {
        FILE * file = fopen("in_20.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        if (!matrix)
        {
            ok_count++;
        }
        fclose(file);
    }

    //result
    printf("%s: %s\n", func, (ok_count == 8) ? "OK" : "FAILED");
}

void determinant_tests(void)
{
    int ok_count = 0;

    // 1 test
    {
        double res = 1.5;
        FILE * file = fopen("in_1.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        double det;
        int flag = determinant(matrix, &det);
        if ((fabs(det - res) <= EPS) && !flag)
        {
            ok_count++;
        }
        free_matrix(matrix);
        fclose(file);
    }

    // 2 test
    {
        FILE * file = fopen("in_2.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        double det;
        int flag = determinant(matrix, &det);
        if (flag)
        {
            ok_count++;
        }
        free_matrix(matrix);
        fclose(file);
    }

    //result
    printf("%s: %s\n", func, (ok_count == 2) ? "FAILED" : "OK");
}

int matrix_cmp(int rows, int columns, double data_a[rows][columns], double **data_b)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (data_a[i][j] != data_b[i][j])
            {
                return -1;
            }
        }
    }
    return 0;
}

void addition_matrix_tests(void)
{
    int ok_count = 0;

    // 1 test
    {
        double data[3][3] = 
            {
                {3.0, 4.0, 6.0},
                {8.0, 10.0, 12.0},
                {14.0, 16.0, 18.0}
            };
        FILE * file = fopen("in_1.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);

        matrix_s *new_matrix = addition_matrix(matrix, matrix);
        if (!matrix_cmp(new_matrix->rows, new_matrix->columns, data, new_matrix->data))
        {
            ok_count++;
        }
        free_matrix(new_matrix);
        free_matrix(matrix);
        fclose(file);
    }

    // 2 test
    {
        double data[3][3] = 
            {
                {2.5, 4.0, 6.0},
                {8.0, 10.0, 12.0},
                {14.0, 16.0, 18.0},
            };

        FILE * file = fopen("in_1.txt", "r");
        FILE * file1 = fopen("in_4.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        matrix_s *matrix1 = create_matrix_from_file(file1);

        matrix_s *new_matrix = addition_matrix(matrix, matrix1);
        if (!matrix_cmp(new_matrix->rows, new_matrix->columns, data, new_matrix->data))
        {
            ok_count++;
        }
        free_matrix(new_matrix);
        free_matrix(matrix);
        fclose(file1);
        fclose(file);
    }

    // 3 test
    {
        FILE * file1 = fopen("in_1.txt", "r");
        FILE * file2 = fopen("in_2.txt", "r");
        matrix_s *matrix_a = create_matrix_from_file(file1);
        matrix_s *matrix_b = create_matrix_from_file(file2);

        matrix_s *new_matrix = addition_matrix(matrix_a, matrix_b);
        if (!new_matrix)
        {
            ok_count++;
        }
        free_matrix(matrix_a);
        free_matrix(matrix_b);
        fclose(file1);
        fclose(file2);
    }

    // result
    printf("%s: %s\n", func, (ok_count == 3) ? "OK" : "FAILED");
}

void multiply_matrix_tests(void)
{
    int ok_count = 0;

    // 1 test
    {
        double data[3][3] = 
            {
                {31.25, 37.0, 43.5},
                {68.0, 81.0, 96.0},
                {105.5, 126.0, 150.0}
            };

        FILE * file = fopen("in_1.txt", "r");
        FILE * file1 = fopen("in_1.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        matrix_s *matrix1 = create_matrix_from_file(file1);

        matrix_s *new_matrix = multiply_matrix(matrix, matrix1);
        if (!matrix_cmp(new_matrix->rows, new_matrix->columns, data, new_matrix->data))
        {
            ok_count++;
        }
        free_matrix(new_matrix);
        free_matrix(matrix);
        fclose(file1);
        fclose(file);
    }

    // 2 test
    {
        double data[3][2] = 
            {
                {30.5, 37.0},
                {66.0, 81.0},
                {102.0, 126.0}
            };

        FILE * file = fopen("in_1.txt", "r");
        FILE * file1 = fopen("in_2.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        matrix_s *matrix1 = create_matrix_from_file(file1);

        matrix_s *new_matrix = multiply_matrix(matrix, matrix1);
        if (!matrix_cmp(new_matrix->rows, new_matrix->columns, data, new_matrix->data))
        {
            ok_count++;
        }
        free_matrix(new_matrix);
        free_matrix(matrix);
        fclose(file1);
        fclose(file);
    }

    // 3 test
    {
        FILE * file = fopen("in_1.txt", "r");
        FILE * file1 = fopen("in_6.txt", "r");
        matrix_s *matrix = create_matrix_from_file(file);
        matrix_s *matrix1 = create_matrix_from_file(file1);

        matrix_s *new_matrix = multiply_matrix(matrix, matrix1);
        if (!new_matrix)
        {
            ok_count++;
        }
        free_matrix(matrix1);
        free_matrix(matrix);
        fclose(file1);
        fclose(file);
    }

    // result
    printf("%s: %s\n", func, (ok_count == 3) ? "OK" : "FAILED");
}
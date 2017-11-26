#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "matrix.h"
#include "constant.h"

/*
* Функция считывания(создания) матрицы из файла. Возвращает считанную матрицу или NULL(ошибка).  
* file - файл из которого производится считывание.  
*/
matrix_s *create_matrix_from_file(FILE *file)
{
	int row = 0, col = 0;
	if (fscanf(file, "%d %d", &row, &col) != 2)
	{
		return NULL;
	}

	if ((row <= 0) || (col <= 0))
	{
		return NULL;
	}
	
	matrix_s *matrix = create_matrix(row, col);
	if (!matrix)
	{
		return NULL;
	}
	
	int rc = 1;
	for (row = 0; row < matrix->rows; ++row)
	{
		for (col = 0; col < matrix->columns; ++col)
		{
			rc = fscanf(file, "%lf", &((*matrix).data[row][col]));
			if (rc == 0 || rc == -1)
			{
				free_matrix(matrix);
				return NULL;
			}
		}
	}
	return matrix;
}

/*
* Функция создания матрицы(выделение памяти). Возвращает созданую матрицу или NULL(ошибка).  
* row - кол-во эл-тов в строке массива, который надо создать.  
* column - кол-во эл-тов в столбце массива, который надо создать.  
*/
matrix_s *create_matrix(int row, int col)
{
	matrix_s *matrix;
	matrix = (matrix_s*) malloc(sizeof(matrix_s));
	if (!matrix)
	{
		return NULL;
	}
	matrix->columns = col;
	matrix->rows = row;
	matrix->data = malloc(row * sizeof(double*) + row * col * sizeof(double));
	/*
	matrix->data = (double**) calloc(row, sizeof(double*));
	*/
	if (!(matrix->data))
	{
		free(matrix);
		return NULL;
	}
	for (int i = 0; i < row; ++i)
	{
		matrix->data[i] = (double*)((char*)matrix->data + row * sizeof(double*) + i * col * sizeof(double));
		/*matrix->data[i] = (double*) calloc(col, sizeof(double));
		if (!(matrix->data[i]))
		{
			free_matrix(matrix);
			return NULL;
		}*/
	}
	
	return matrix;
}

/*
* Функция удаления матрицы.  
* matrix - матрицу, которую надо удалить.  
*/
void free_matrix(matrix_s *matrix)
{
	/*
	for (int i = 0; i < matrix->rows; ++i)
	{
		free(matrix->data[i]);
	}
	*/
	free(matrix->data);
	free(matrix);
}

/*
* Статическая функция создания дополнительного минора. Возвращает дополнительный минор или NULL(ошибку).  
* matrix - матрица из которой берется дополнительный минор.  
* count - кол-во эл-тов в строке или столбце matrix.  
* exclude_row - 
* exclude_column - 
*/
static matrix_s *matrix_det(int count, int exclude_row, int exclude_column, const matrix_s *matrix)
{
	matrix_s *new_matrix = create_matrix(count - 1, count - 1);
	if (!new_matrix)
	{
		return NULL;
	}

	int ki = 0, kj = 0;
	for (int i = 0; i < count - 1; ++i)
	{
		if (i == exclude_row)
		{
			ki = 1;
		}
		for (int j = 0; j < count - 1; ++j)
		{
			if (j == exclude_column)
			{
				kj = 1;
			}
			new_matrix->data[i][j] = matrix->data[i + ki][j + kj];
		}
	}
	return new_matrix;
}

/*
* Статическая функция высчитывания значения определителя. Возвращает  (значения определителя и flag = OK) или (0 и flag = ERROR_DETERMINANT(ошибку)).  
* matrix - матрица из которой высчитывается значение определителя.  
* count - кол-во эл-тов в строке или столбце matrix.  
* flag - Проверка высчитывания значения определителя.  
*/
static double determinant_value(int count, const matrix_s *matrix, int *flag)
{
	int sign = 1, new_count = count - 1;
	double det = 0;
	if (count == 1)
	{
		return matrix->data[0][0];
	}
	if (count == 2)
	{
		return ((matrix->data[0][0] * matrix->data[1][1]) - (matrix->data[1][0] * matrix->data[0][1]));
	}
	if (count > 2)
	{
		for (int i = 0; i < count; ++i)
		{
			matrix_s *new_matrix = matrix_det(count, i, 0, matrix);
			if (!new_matrix)
			{
				*flag = ERROR_DETERMINANT;
				return 0;
			}
			det = det + sign * matrix->data[i][0] * determinant_value(new_count, new_matrix, flag);
			sign = -sign;
			free_matrix(new_matrix);
		}
	}
	return det;
}

/*
* Функция высчитывания значения определителя. Возвращает flag-считывания OK - все хорошо или ERROR_DETERMINANT - ошибка.  
* matrix - матрица из которой высчитывается значение определителя.  
* det - значение определителя.  
*/
int determinant(const matrix_s *matrix, double *det)
{
	if (!(matrix->rows == matrix->columns))
	{
		return ERROR_DETERMINANT;
	}
	int flag = OK;
	*det = determinant_value(matrix->rows, matrix, &flag);
	if (flag)
	{
		return ERROR_DETERMINANT;
	}
	return OK;
}

/*
* Функция вычисления суммы матриц matrix_a и matrix_b. Возвращает сумму матриц или NULL(ошибку).  
* matrix_a/matrix_b - матрицы для суммирования.  
*/
matrix_s *addition_matrix(matrix_s *matrix_a, matrix_s *matrix_b)
{
	if (!((matrix_a->rows == matrix_b->rows) && (matrix_a->columns == matrix_b->columns)))
	{
		return NULL;
	}
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_a->columns);
	if (!new_matrix)
	{
		return NULL;
	}
	for (int i = 0; i < matrix_a->rows ; ++i)
	{
		for (int j = 0; j < matrix_a->columns; ++j)
		{
			new_matrix->data[i][j] = matrix_a->data[i][j] + matrix_b->data[i][j];
		}
	}
	return new_matrix;
}

/*
* Функция вычисления произведения матриц matrix_a и matrix_b. Возвращает произведение матриц или NULL(ошибку).  
* matrix_a/matrix_b - матрицы для произведения.  
*/
matrix_s *multiply_matrix(matrix_s *matrix_a, matrix_s *matrix_b)
{
	if (!(matrix_a->columns == matrix_b->rows))
	{
		return NULL;
	}
	matrix_s *new_matrix = create_matrix(matrix_a->rows, matrix_b->columns);
	if (!new_matrix)
	{
		return NULL;
	}
	for (int i = 0; i < matrix_a->rows; ++i)
	{
		for (int j = 0; j < matrix_b->columns; ++j)
		{
			new_matrix->data[i][j] = 0;
			for (int k = 0; k < matrix_b->rows; ++k)
			{
				new_matrix->data[i][j] += matrix_a->data[i][k] * matrix_b->data[k][j];
			}
		}
	}

	return new_matrix;
}

/*
* Функция печати матрицы в поток(консоль).  
* matrix - матрица, которая будет напечатана.  
*/
void print_matrix(const matrix_s *matrix)
{
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			printf("%f ", matrix->data[i][j]);
		}
		printf("\n");
	}
}

/*
* Функция печати матрицы в файл.  
* file_write - файл, в который будет произведена запись.  
* matrix - матрица, которая будет напечатана.  
*/
void print_to_file(FILE *file_write, const matrix_s *matrix)
{
	fprintf(file_write, "%d %d\n", matrix->rows, matrix->columns);
	for (int i = 0; i < matrix->rows; ++i)
	{
		for (int j = 0; j < matrix->columns; ++j)
		{
			fprintf(file_write, "%f", matrix->data[i][j]);
			fprintf(file_write, "%c", ' ');
		}
		if (i != matrix->rows - 1)
			fprintf(file_write, "%c", '\n');
	}
}
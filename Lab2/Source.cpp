#include <iostream>

int askUserWayFormMatrix()
{
	int choise;
	do {
		printf("Введите:\n1 - сформировать матрицу через одномерный массив\n2 - сформировать матрицу через массив указателей\nВыбор:");
		scanf_s("%d", &choise);
	} while (choise > 2 || choise < 1);
	return choise;
}

int scanMatrixSize(const char name[])
{
	int choise;
	do {
		printf("Введите количество %s [0;100000]:\n", name);
		scanf_s("%d", &choise);
	} while (choise > 100000 || choise < 0);
	return choise;
}

int** allocateMatrix(int rows, int cols)
{
	int** matrix = (int**)malloc(sizeof(int*) * rows);
	for (int i = 0; i < rows; i++)
		matrix[i] = (int*)malloc(sizeof(int) * cols);
	return matrix;
}

void fillMasManually(int* mas, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			printf("mas[%d][%d] = ", i, j);
			scanf_s("%d", (mas + i * cols + j));
		}
}

void fillMatrixManually(int** matrix, int rows, int cols)
{
	for(int i=0;i<rows;i++)
		for (int j = 0; j < cols; j++)
		{
			printf("matrix[%d][%d] = ", i, j);
			scanf_s("%d", &matrix[i][j]);
		}
}

void outputMasToScreen(int* mas, int rows, int cols)
{
	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%3d ", *(mas + i * cols + j));
		printf("\n");
	}
	printf("\n");
}

void outputMatrixToScreen(int** matrix, int rows, int cols)
{
	printf("\n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%3d ", matrix[i][j]);
		printf("\n");
	}
	printf("\n");
}

void avArithmeticPositiveElem1(int* mas, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		float sum = 0;
		int counter = 0;
		for (int j = 0; j < cols; j++)
			if (*(mas + i * cols + j) >= 0)
			{
				sum += *(mas + i * cols + j);
				counter++;
			}
		sum /= counter;
		printf("№%d - %d(%.1f)\n", i + 1, counter, sum);
	}
}

void avArithmeticPositiveElem2(int** matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		float sum = 0;
		int counter = 0;
		for (int j = 0; j < cols; j++)
			if (matrix[i][j] >= 0)
			{
				sum += matrix[i][j];
				counter++;
			}
		sum /= counter;
		printf("№%d - %d(%.1f)\n", i + 1, counter, sum);
	}
}

int main()
{
	//1. Вычислить среднее арифметическое неотрицательных элементов матрицы, а также определить,
	//сколько таких элементов в каждой отдельно взятой строке матрицы.
	system("chcp 1251");

	switch (askUserWayFormMatrix())
	{
	case 1:
	{
		int rows = scanMatrixSize("строк");
		int cols = scanMatrixSize("столбцов");
		int* mas = (int*)malloc(sizeof(int) * rows * cols);

		fillMasManually(mas, rows, cols);
		outputMasToScreen(mas, rows, cols);
		avArithmeticPositiveElem1(mas, rows, cols);
		break;
	}
	case 2:
	{
		int rows = scanMatrixSize("строк");
		int cols = scanMatrixSize("столбцов");
		int** matrix = allocateMatrix(rows, cols);

		fillMatrixManually(matrix, rows, cols);
		outputMatrixToScreen(matrix, rows, cols);
		avArithmeticPositiveElem2(matrix, rows, cols);
		break;
	}
	}

	return 0;
}
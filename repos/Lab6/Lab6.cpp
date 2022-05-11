#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n, m;
	int** matrix;
	int* resultMatrix;
	printf(" Input size N : ");
	scanf_s("%d", &n);
	printf(" Input size M : ");
	scanf_s("%d", &m);
	resultMatrix = new int[m];

	matrix = new int* [n];
	for (int row = 0; row < n; row++)
	{
		matrix[row] = new int[m];
	}

	puts("\n Input Massiv A:");
	for (int row = 0; row < n; row++)
	{
		for (int column = 0; column < m; column++)
		{
			scanf_s("%d", &matrix[row][column]);
		}
	}

	for (int column = 0; column < m; column++)
	{
		int resultValue = 0;
		for (int row = 0; row < n; row++)
		{
			if (matrix[row][column] != 0) {
				resultValue = 1;
				break;
			}
		}
		resultMatrix[column] = resultValue;
	}

	puts("\n  Massiv A:");
	for (int row = 0; row < n; row++)
	{
		
		for (int column = 0; column < m; column++)
		{
			printf("%d \t", matrix[row][column]);
		}
		printf("\n");
	}

	puts("\n\n Result Massiv B:");
	for (int k = 0; k < m; k++)
	{
		printf("%d \t", resultMatrix[k]);
	}

	delete[] matrix;
	delete[] resultMatrix;
	return 0;
}


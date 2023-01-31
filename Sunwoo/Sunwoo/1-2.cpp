#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip> // ��½� ĭ ���� ���� STL
#include <cstdlib>
#include <ctime>
using namespace std;
void bubble_sort(int list[], int n);

int main()
{
	srand(time(0));
	int i, j;

	int** matrix = new int* [10];
	for (i = 0; i < 10; i++)
		*(matrix + i) = new int[10];


	cout << "Sort by row" << endl;






	int i, j;
	int** matrix;

	matrix = (int**)malloc(sizeof(int*) * 10);
	for (i = 0; i < 10; i++)
		matrix[i] = (int*)malloc(sizeof(int) * 11);

	for (i = 0; i < 10; i++)
	{
		matrix[i][10] = 0;
		for (j = 0; j < 10; j++) {
			matrix[i][j] = rand() % 101;
			matrix[i][10] += matrix[i][j];
		}
	}

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			cout << setw(6) << matrix[i][j];
		cout << "   Sum is " << matrix[i][10] << "(" << &matrix[i][10] << ")" << endl;
	}


	for (i = 0; i < 10; i++)
		bubble_sort(*(matrix + i), 10);
	cout << endl << "Sort by row" << endl;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			cout << setw(6) << matrix[i][j];
		cout << "   Sum is " << matrix[i][10] << "(" << &matrix[i][10] << ")" << endl;
	}


	for (i = 0; i < 10; i++)
		bubble_sort(&matrix[i][10], 10);

	cout << endl << "Sort by sum" << endl;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
			cout << setw(6) << matrix[i][j];
		cout << "   Sum is " << matrix[i][10] << "(" << &matrix[i][10] << ")" << endl;
	}



	for (i = 0; i < 10; i++)
		free(matrix[i]);
	free(matrix);

	return 0;
}

void bubble_sort(int *list, int n) 
{
	int i, j, temp;

	for (i = n - 1; i > 0; i--) // 0 ~ (i-1)���� �ݺ�
		for (j = 0; j < i; j++) // j��°�� j+1��°�� ��Ұ� ũ�� ���� �ƴϸ� ��ȯ
			if (list[j] > list[j + 1]) 
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
}
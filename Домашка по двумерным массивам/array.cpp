#include "function.h"
#include <iostream>
#include <ctime>
using namespace std;

void create_array(int**& array, int rows, int cols)
{
	array = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		array[i] = new int[cols];
	}
}

void print_array(int** array)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void random_array(int** array)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	int MIN = -50;
	int MAX = 50;

	srand(time(NULL));
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			array[i][j] = MIN + rand() % (MAX - MIN + 1);
		}
	}
}

void input_array(int** array)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> array[i][j];
		}
	}
}

void delete_array(int**& array)
{
	int rows = _msize(array) / sizeof(*array);
	for (int i = 0; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

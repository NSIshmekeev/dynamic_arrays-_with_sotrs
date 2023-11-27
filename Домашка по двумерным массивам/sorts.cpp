#include "function.h"
#include <iostream>
using namespace std;

void merge(int* &list, int start, int end, int mid)
{
	int* mergedList = new int[end + 1];

	int i = start, j = mid + 1, k = start;
	while (i <= mid && j <= end)
	{
		if (list[i] < list[j])
		{
			mergedList[k] = list[i];
			k++;
			i++;
		}
		else
		{
			mergedList[k] = list[j];
			k++;
			j++;
		}

	}
	while (i <= mid) {
		mergedList[k] = list[i];
		k++;
		i++;
	}

	while (j <= end) {
		mergedList[k] = list[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {
		list[i] = mergedList[i];
	}
}

void merge_sort(int *&list, int start, int end)
{
	int mid;
	if (end > start)
	{
		mid = (end + start) / 2;
		merge_sort(list, start, mid);
		merge_sort(list, mid + 1, end);
		merge(list, start, end,mid);
	}
}

void merge_array(int** array)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	for (int i = 0; i < rows; i++)
	{
		merge_sort(array[i], 0, cols - 1);
	}
}

auto custom_swap{[](int* list, int a, int b, int tmp = NULL){tmp = list[a]; list[a] = list[b]; list[b] = tmp;}};

void my_quick_sort(int* list, int size)
{
	int i = 0;
	int j = size - 1;
	int mid = list[size / 2];
	do 
	{
		while (list[i] < mid) i++;
		while (list[j] > mid) j--;
		if (i <= j)
		{
			custom_swap(list, i, j);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		my_quick_sort(list, j + 1);
	}
	if (i < size)
	{
		my_quick_sort(&list[i], size - i);
	}
}

void quick_sort2D(int** array)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	for (int i = 0; i < rows; i++)
	{
		my_quick_sort(array[i], cols);
	}
}


// Быстрая сортировка с компаратором
void my_quick_sort(int* list, int size, funcmp cmp)
{
	int i = 0;
	int j = size - 1;
	int mid = list[size / 2];
	do
	{
		while (cmp(list[i], mid)) i++;
		while (cmp(mid, list[j])) j--;
		if (i <= j)
		{
			custom_swap(list, i, j);
			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0)
	{
		my_quick_sort(list, j + 1, cmp);
	}
	if (i < size)
	{
		my_quick_sort(&list[i], size - i, cmp);
	}
}

void quick_sort2D(int** array, funcmp cmp)
{
	int rows = _msize(array) / sizeof(*array);
	int cols = _msize(*array) / sizeof(**array);
	for (int i = 0; i < rows; i++)
	{
		my_quick_sort(array[i], cols, cmp);
	}
}
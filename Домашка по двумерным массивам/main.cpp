#include <iostream>
#include "function.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int** array;
	cout << "Введите кол-во строк и стобцов" << endl;
	int rows, cols;
	funcmp comp1 = &comparator1;
	funcmp comp2 = &comparator2;
	cin >> rows >> cols;
	cout << "Создание массива" << endl;
	create_array(array, rows, cols);
	random_array(array);
	print_array(array);
	cout << endl;
	cout << "Быстрая сортировка массива без компаратора" << endl;
	quick_sort2D(array);
	print_array(array);
	cout << endl;
	cout << "Быстрая сортировка массива c компаратором (сравнивание по квадрату числа)" << endl;
	quick_sort2D(array, comp1);
	print_array(array);
	cout << endl;
	cout << "Быстрая сортировка массива c компаратором (сравнивание по остатку деления числа на 10, отстаток от отприцательных чисел берется от модуля)" << endl;
	quick_sort2D(array, comp2);
	print_array(array);
	cout << endl;
	cout << "Сортировка слиянием" << endl;
	merge_array(array);
	print_array(array);
	delete_array(array);

	return 0;
}
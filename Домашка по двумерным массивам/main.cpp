#include <iostream>
#include "function.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int** array;
	cout << "������� ���-�� ����� � �������" << endl;
	int rows, cols;
	funcmp comp1 = &comparator1;
	funcmp comp2 = &comparator2;
	cin >> rows >> cols;
	cout << "�������� �������" << endl;
	create_array(array, rows, cols);
	random_array(array);
	print_array(array);
	cout << endl;
	cout << "������� ���������� ������� ��� �����������" << endl;
	quick_sort2D(array);
	print_array(array);
	cout << endl;
	cout << "������� ���������� ������� c ������������ (����������� �� �������� �����)" << endl;
	quick_sort2D(array, comp1);
	print_array(array);
	cout << endl;
	cout << "������� ���������� ������� c ������������ (����������� �� ������� ������� ����� �� 10, �������� �� �������������� ����� ������� �� ������)" << endl;
	quick_sort2D(array, comp2);
	print_array(array);
	cout << endl;
	cout << "���������� ��������" << endl;
	merge_array(array);
	print_array(array);
	delete_array(array);

	return 0;
}
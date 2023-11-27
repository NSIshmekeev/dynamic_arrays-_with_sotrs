#include "function.h"
#include <iostream>
using namespace std;

bool comparator1(int a, int b)
{
	return (a * a) < (b * b);
}

bool comparator2(int a, int b)
{
	return (abs(a) % 10) < (abs(b) % 10);
}
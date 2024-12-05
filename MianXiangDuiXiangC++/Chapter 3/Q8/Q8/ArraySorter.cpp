// ArraySorter.cpp: Class function Implementation file
#include "ArraySorter.h"
#include <iostream>
#include <algorithm>

// Comparator function; For std:sort.
bool compare_des(int a, int b) {
	return a > b;
}

// Class function implementation
void ArraySorter::operator() (int* arr, int size) {
	std::sort(arr, arr + size, compare_des);
}

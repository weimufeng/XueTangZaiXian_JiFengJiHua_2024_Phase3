// Source.cpp: main test file
#include "ArraySorter.h"
#include <iostream>

using namespace std;

int main() {
	// Array and array size
	int arr[] = { 3,1,4,2,5 };
	int size = sizeof(arr) / sizeof(arr[0]);

	// Declare and initize class object
	ArraySorter sorter;
	// Test overloaded ()
	sorter(arr, size);

	// Print out sorted array
	for (int i : arr) {
		cout << i << " ";
	}
	cout << endl;

	return 0;
}
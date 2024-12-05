// main.cpp: main file, test class

#include "GradeReporter.h"
#include <iostream>

using namespace std;

int main() {
	// Initialize grades int array
	int arr[] = {55, 2, 2, 21, 4, 56, 23, 32, 12, 56, 76, 33, 44, 77, 88, 99, 100, 93, 71, 3};
	int size = sizeof(arr) / sizeof(arr[0]);

	// Test [] overload
	GradeReporter reporter = GradeReporter(arr, size);
	cout << "1-10: " << reporter[0] << endl;
	cout << "51-60: " << reporter[5] << endl;
	cout << "91-100: " << reporter[9] << endl;

	return 0;
}
// GradeReporter.cpp: class implementation file
#include "GradeReporter.h"

// constructor
GradeReporter::GradeReporter(int* arr, int size) {
	arr_ = arr;
	size_ = size;
}

// [] overload
int GradeReporter::operator[] (const int k) const {
	int res = 0;
	for (int i = 0; i < size_; i++) {
		if (arr_[i] >= 10 * k + 1 && arr_[i] <= 10 * k + 10) {
			res++;
		}
	}
	return res;
}
// GradeReporter.h: header file

#pragma once
class GradeReporter
{
private:
	int* arr_;
	int size_;
public:
	// constructor
	GradeReporter(int* arr, int size);
	// [] overload
	int operator[] (const int k) const;
};


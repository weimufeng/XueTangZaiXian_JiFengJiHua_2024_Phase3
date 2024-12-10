#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Log
{
private:
	string level;

public:
	Log() { level = "warning"; };
	Log(string l) { level = "l"; };
	// void set_level(string l);

	friend ostream& operator << (ostream& out, const string& m);
};


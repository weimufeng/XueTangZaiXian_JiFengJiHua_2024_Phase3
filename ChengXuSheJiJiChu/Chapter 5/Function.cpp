// Pass

//定义递归函数f(x) :
//
//	当x = 1时，f(x) = 1。
//
//	当x > 1且为奇数时f(x) = f((x - 1) / 2) + f((x + 1) / 2)
//
//	当x为偶数时f(x) = f(x / 2)
//
//	请编写程序，完成对f(x)的计算
//
//	输入描述
//	第一行一个正整数T，表示数据组数。（T <= 100）
//
//	之后T行，每行一个正整数x。（x <= 10 ^ 9）
//
//	输出描述
//	对于每组数据，输出一行答案。
//
//	示例1 :
//输入：
//3
//1
//3
//10
//输出：
//1
//2
//3

#include <iostream>
using namespace std;

int calculate(int x) {
	if (x == 1) {
		return 1;
	}
	else if (x % 2 == 1 && x > 1) {
		return calculate((x - 1) / 2) + calculate((x + 1) / 2);
	}
	else if (x % 2 == 0) {
		return calculate(x / 2);
	}
}


int main() {
	int x;
	int* T = new int[x];
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> T[i];
	}

	for (int i = 0; i < x; i++) {
		cout << calculate(T[i]) << endl;
	}

	delete[] T;
	return 0;
}
// Pass

//斐波那契数列f(n)满足以下定义：
//
//f(0) = 1, f(1) = 1, f(n) = f(n - 1) + f(n - 2) (n >= 2)。
//
//对于给定的n，求出斐波那契数列的第n项f(n)
//
//输入描述
//每行输入一个整数n。
//
//0 <= n <= 30
//
//输出描述
//对于每一行输入，输出斐波那契数列第n项的值f(n)。
//
//示例1 :
//输入：
//1
//10
//25
//输出：
//1
//89
//121393

#include <iostream>

using namespace std;

int arr[3];
int n;

int fibonacci(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;
	}
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	cin >> n;
	cout << fibonacci(n) << endl;

	return 0;
}
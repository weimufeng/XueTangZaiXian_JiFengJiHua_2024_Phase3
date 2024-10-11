// Pass

//有一个数列，f(n) = f(n - 1) + f(n//2) + f(n//3)，其中n//m表示整除。 如 3//2=1, 4//2=2, 5//2=2。
//
//    当n <= 0时，有f(n) = 0。
//
//    现在告诉你f(1) = x，请计算f(n)的值.
//
//    请使用递归完成计算。
//
//    输入描述
//    输入两个整数x、n。
//
//    0 < x，n <= 20
//
//    输出描述
//    输出f(n)的值。
//
//    示例1 :
//输入：
//1 6
//
//输出：
//16
//提示
//样例含义
//
//f(1) = 1
//
//f(2) = f(1) + f(1) + f(0) = 1 + 1 + 0 = 2
//
//f(3) = f(2) + f(1) + f(1) = 2 + 1 + 1 = 4
//
//f(4) = f(3) + f(2) + f(1) = 4 + 2 + 1 = 7
//
//f(5) = f(4) + f(2) + f(1) = 7 + 2 + 1 = 10
//
//f(6) = f(5) + f(3) + f(2) = 9 + 4 + 2 = 16

#include <iostream>
using namespace std;

int calculate(int x, int N) {
	if (N <= 0) {
		return 0;
	}
	else if (N == 1) {
		return x;
	}
	else {
		return calculate(x, N - 1) + calculate(x, N / 2) + calculate(x, N / 3);
	}
}


int main() {
	int x, N;
	cin >> x;
	cin >> N;

	int result = calculate(x, N);
	cout << result << endl;
	return 0;
}
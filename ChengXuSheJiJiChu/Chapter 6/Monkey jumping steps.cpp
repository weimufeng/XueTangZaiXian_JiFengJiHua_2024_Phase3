// Partial Pass

//一个顽猴在一座有N级台阶的小山上爬山跳跃，猴子上山一步可跳x级或跳y级，试求猴子上山到N级台阶有多少种不同的爬法？猴子从山脚开始跳，可认为是第0阶。
//
//输入描述
//三个正整数N, X, Y，用空格隔开。 （x <= y <= N <= 100）
//
//输出描述
//猴子上山到第N级台阶有多少种不同的爬法, 如果不能到达则输出“sorry”。
//
//示例1 :
//输入：
//3 1 2
//
//输出：
//3
//提示
//保证最终答案不超过int范围

#include <iostream>

using namespace std;

int N, X, Y;

bool pre_check(int n, int x, int y) {
    if (n < 0) {
        return false;
    }

    if (n == x || n == y) {
        return true;
    }

    return (pre_check(n - x, x, y) || pre_check(n - y, x, y));
}

int climb(int n, int x, int y) {
    // Base case
    if (n < x) {
        return 0;
    }
    if (n == y) {
        if (y % x == 0 && y > x) {
            return 2;
        }
        return 1;
    }

    if (n == x) {
        return 1;
    }

    return climb(n - x, x, y) + climb(n - y, x, y);
}

int main() {
    cin >> N;
    cin >> X;
    cin >> Y;

    if (!pre_check(N, X, Y)) {
        cout << "sorry";
    }
    else {
        cout << climb(N, X, Y);
    }

    //    cout << pre_check(5, 4, 2);

    return 0;
}
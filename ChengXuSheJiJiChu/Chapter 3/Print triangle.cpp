// Pass

//请编程输出长度为n的实心等腰直角三角形。
//
//输入描述
//输入一个整数n。(0 < n <= 10)
//
//    输出描述
//    输出长度为n的实心等腰直角三角形。具体格式见样例。
//
//    示例1 :
//输入：
//4
//输出：
//```
//*
//**
//***
//****
//```

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n; 

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << '*';  // Print '*' i times
        }
        cout << endl;  // Move to the next line after printing the stars
    }

    return 0;
}

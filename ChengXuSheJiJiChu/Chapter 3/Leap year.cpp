// Pass

//输入一个年份，判断其是否是闰年。
//
//输入描述
//输入一个整数a。(1000 <= a <= 10000)
//
//输出描述
//如果是闰年，输出"YES"，否则输出"NO"。
//
//示例1 :
//输入：
//1900
//输出：
//NO

#include <iostream>

using namespace std;

int main() {
    int year;
    cin >> year;

    if (year % 4 == 0) {
        if (year % 100 != 0) {
            cout << "YES" << endl;
        }
        else if (year % 400 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}

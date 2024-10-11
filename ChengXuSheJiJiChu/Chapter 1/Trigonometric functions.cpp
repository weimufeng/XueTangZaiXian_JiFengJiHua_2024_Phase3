// Pass

//计算下列式子中y的值
//
//y = sin(π / 4) ^ 2 + sin(π / 4)cos(π / 4) - cos(π / 4) ^ 2
//
//输入描述
//无
//
//输出描述
//y 的值，保留5位小数

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float pi = acos(-1);
    cout << fixed << setprecision(5) << pow(sin(pi/4), 2) + sin(pi/4) * cos(pi/4) - pow(cos(pi/4), 2) <<  endl;
    return 0;
}
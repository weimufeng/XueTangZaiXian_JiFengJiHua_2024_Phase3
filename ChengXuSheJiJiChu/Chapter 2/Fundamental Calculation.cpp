// Pass

//小明画了一个圆形的饼。这个饼的半径为2.52384，问这个饼的面积有多大？（pi取3.1415926）
//
//输入描述
//无
//
//输出描述
//无

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float r = 2.52384;
    float pi = 3.1415926;
    float area = r * r * pi;
    
    cout << fixed << setprecision(4) << area <<  endl;
    return 0;
}
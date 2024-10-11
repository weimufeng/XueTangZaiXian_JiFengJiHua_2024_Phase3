// Pass

//给定一个三角形的三条边的边长（符合三角形的构成条件），求三角形的面积。
//
//输入描述
//输入仅有一行，为三个实数a，b，c（a > 0，b > 0，c > 0），代表三角形的三条边的边长。
//
//输出描述
//输出仅有一行，为一个实数S（精确到两位小数），代表三角形的面积。
//
//示例1 :
//输入：
//1.0 1.0 1.0
//输出：
//0.43

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    
    float p = (a + b + c) / 2;
    float area = sqrt(p * (p - a) * (p - b) * (p - c));
    
    cout << fixed << setprecision(2) << area <<  endl;
    return 0;
}
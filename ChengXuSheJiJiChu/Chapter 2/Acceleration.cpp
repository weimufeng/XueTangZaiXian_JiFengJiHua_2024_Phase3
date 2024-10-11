// Pass

//小I进行匀加速运动，初始速度为 0 m / s，t秒后，速度为 v m / s，问加速度是多少（m / s ^ 2）？
//
//输入描述
//输入两个整数v, t。(0 < v, t <= 1000)
//
//    输出描述
//    输出物体的加速度，保留4位小数。
//
//    示例1 :
//输入：
//4 2
//输出：
//2.0000

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    float v, t;
    cin >> v;
    cin >> t;
    
    float a = v / t;
    
    cout << fixed << setprecision(4) << a <<  endl;
    return 0;
}
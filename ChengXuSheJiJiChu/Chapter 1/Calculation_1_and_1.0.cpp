// Pass

//计算1 + 1 / (1 + 1 / (1 + 1 / 5))
//
//输入描述
//无
//
//输出描述
//保留四位小数
//
//示例1 :
//输入：
//无
//输出：
//无
//提示
//使用cout输出时，小数点后保留4位数字的示例程序：
//
//```
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << fixed << setprecision(4) << 1.0 + 1.0 / (1.0 + 1.0 / (1.0 + 1.0 / 5.0)) <<  endl;
    return 0;
}
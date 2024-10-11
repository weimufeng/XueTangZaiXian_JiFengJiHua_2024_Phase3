// Pass

//数学里有一个函数叫做max(a, b)，为a和b中更大的那一个。
//
//现在，请完成函数max2，要求返回当前遇见过的所有数字中，第二大的数字。
//
//你只能使用全局变量a1和a2来保存信息，不能使用数组来存储。
//
//(允许再另外使用两个变量分别用于存储n和用于输入正整数)
//
//输入描述
//第一行一个数字n，表示有n个正整数，2 <= n <= 100。
//
//第二行有n个正整数，分别是数列的n项，数列各项互不相等。
//
//输出描述
//输出只有一行，一个整数，表示数列的第二大数字。
//
//示例1 :
//输入：
//10
//
//10 9 8 7 6 5 4 3 2 1
//输出：
//9

#include <iostream>

using namespace std;

int main() {
    int n;

    // Take input for the size of the array
    cin >> n;

    // Define the array after the size is known
    int * arr = new int[n];

    // Input the array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize max1 and max2
    int max1 = arr[0], max2 = arr[1];

    // Swap max1 and max2 if necessary
    if (max1 < max2) {
        int temp = max1;
        max1 = max2;
        max2 = temp;
    }

    // Find the two largest values
    for (int i = 2; i < n; i++) {
        if (arr[i] > max1) {
            int temp = max1;
            max1 = arr[i];
            max2 = temp;
        }
        else if (arr[i] > max2) {
            max2 = arr[i];
        }
    }
    cout << max2 << endl;

    delete[] arr;
    return 0;
}
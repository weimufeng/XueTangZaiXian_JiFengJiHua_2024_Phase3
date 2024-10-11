// Pass

//分解n个大于1的正整数的质因数，并以因子从小到大排序，以等式格式输出。比如
//
//```
//
//12 = 2 * 2 * 3
//
//```
//
//输入描述
//第1行为一个整数n，表示需要进行分解的质因数的数量。(1 <= n <= 100)
//
//第2行到第n + 1行  为需要进行分解的n个正整数x_i。(1 < x_i < 10 ^ 9)
//
//    输出描述
//    共n行，每一行为分解质因数得到的等式，因子从小到大进行排列
//
//    示例1 :
//输入：
//```
//2
//12
//36
//```
//
//输出：
//```
//12 = 2 * 2 * 3
//36 = 2 * 2 * 3 * 3
//```

#include <iostream>

using namespace std;

int main() {
    // Input
    int n;

    // First, input the size of the array
    cin >> n;

    // Declare the array with size `n`
    int * arr = new int[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Factorization of each element
    for (int i = 0; i < n; i++) {
        int t = 2;
        cout << arr[i] << '=';
        while (arr[i] != 1) {
            if (arr[i] % t == 0) {
                cout << t;
                arr[i] = arr[i] / t;
                if (arr[i] != 1) {
                    cout << '*';
                }
                else {
                    cout << endl;
                }
            }
            else {
                t++;
            }
        }
    }

    return 0;
}
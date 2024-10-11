// Pass

//给你一个n* m的矩阵A = (a_ij)，矩阵左上角坐标为(1, 1)，右下角坐标为(n, m)。现在有三种对矩阵的操作：
//
//1.A x1 y1 x2 y2 d，表示在左上角坐标为(x1, y1)右下角坐标为(x2, y2)的矩形中所有数加d，即，对于所有(x1 ≤ i ≤ x2, y1≤ j ≤ y2)，执行a_ij = a_ij + d；
//
//2.E x1 x2，表示将第x1行元素与第x2行元素交换；
//
//3.Q x y，表示询问矩阵中坐标为(x, y)处的值为多少，即a_xy的值。
//
//例如，给定矩阵
//
//A =
//
//[1, 2, 3]
//
//[4, 5, 6]
//
//[7, 8, 9]
//
//* *（看成3 * 3矩阵，下同） * *
//
//对于操作“A 1 1 2 2 1”，矩阵A变为：
//
//[2, 3, 3]
//
//[5, 6, 6]
//
//[7, 8, 9]
//
//接着对于操作“E 1 3”，矩阵A变为：
//
//[7, 8, 9]
//
//[5, 6, 6]
//
//[2, 3, 3]
//
//对于操作“Q 3 3”，输出3。
//
//【输入输出格式】
//
//第一行两个整数n，m，表示矩阵有n行m列。
//
//接下来的n行，每行m个数，表示矩阵里元素的初始值。
//
//第n + 2行有一个整数q，表示操作的次数。
//
//接下来的q行是对操作的描述。
//
//对于每个询问输出结果。
//
//【输入输出格式】
//
//第一行两个整数n，m，表示矩阵有n行m列。
//
//接下来的n行，每行m个数，表示矩阵里元素的初始值。
//
//第n + 2行有一个整数q，表示操作的次数。
//
//接下来的q行是对操作的描述。
//
//对于每个询问输出结果。
//
//输入描述
//无
//
//输出描述
//无
//
//示例1 :
//输入：
//3 4
//
//1 2 3 4
//
//5 6 7 8
//
//9 10 11 12
//
//5
//
//A 1 1 1 2 - 1
//
//E 2 3
//
//A 3 3 3 3 2
//
//Q 2 2
//
//Q 3 1
//
//输出：
//10
//5
//提示
//【数据范围】
//
//50 % 的数据满足1 ≤ n, m ≤10： | a_ij | ≤ 200, 000, q ≤ 10；
//
//100 % 的数据满足1 ≤ n, m ≤100： | a_ij | ≤ 200, 000, q ≤ 100, | d | ≤ 1000；

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Input
    int n, m;
    //cout << "n: , m: " << endl;
    cin >> n;
    cin >> m;

    vector<vector<int>> matrix;
    //cout << "matrix: " << endl;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            row.push_back(x);
        }
        matrix.push_back(row);
    }

    int q;
    //cout << "q: " << endl;
    cin >> q;

    vector<char> o;
    vector<vector<int>> v_A;
    vector<vector<int>> v_E;
    vector<vector<int>> v_Q;

    //cout << "Operations" << endl;
    for (int i = 0; i < q; i++) {
        char op;
        cin >> op;
        o.push_back(op);

        if (op == 'A') {
            vector<int> o_A;
            for (int i = 0; i < 5; i++) {
                int x;
                cin >> x;
                o_A.push_back(x);
            }
            v_A.push_back(o_A);
        }
        else if (op == 'E') {
            vector<int> o_E;
            for (int i = 0; i < 2; i++) {
                int x;
                cin >> x;
                o_E.push_back(x);
            }
            v_E.push_back(o_E);
        }
        else if (op == 'Q') {
            vector<int> o_Q;
            for (int i = 0; i < 2; i++) {
                int x;
                cin >> x;
                o_Q.push_back(x);
            }
            v_Q.push_back(o_Q);
        }
    }

    // Test Input
//    cout << "Test matrix" << endl;
//    for (int i = 0; i < n; i ++) {
//        for (int j = 0; j < m; j ++) {
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    
//    cout << "Test operation" << endl;
//    for (int i = 0; i < q; i++) {
//        cout << o[i] << ' ';
//    }
//    cout << endl;
//    for (vector<int> v:v_A) {
//        for (int i = 0; i < 5; i++) {
//            cout << v[i] << ' ';
//        }
//        cout << endl;
//    }
//    for (vector<int> v:v_E) {
//        for (int i = 0; i < 2; i++) {
//            cout << v[i] << ' ';
//        }
//        cout << endl;
//    }
//    for (vector<int> v:v_Q) {
//        for (int i = 0; i < 2; i++) {
//            cout << v[i] << ' ';
//        }
//        cout << endl;
//    }


    // Output
    int i_A = 0;
    int i_E = 0;
    int i_Q = 0;

    for (char c : o) {
        if (c == 'A') {
            vector<int> indexes = v_A[i_A];
            int add_num = indexes[4];
            for (int i = indexes[0] - 1; i < indexes[2]; i++) {
                for (int j = indexes[1] - 1; j < indexes[3]; j++) {
                    matrix[i][j] += add_num;
                }
            }
            i_A++;
        }
        else if (c == 'E') {
            vector<int> indexes = v_E[i_E];
            vector<int> temp = matrix[indexes[0] - 1];
            matrix[indexes[0] - 1] = matrix[indexes[1] - 1];
            matrix[indexes[1] - 1] = temp;
            i_E++;
        }
        else if (c == 'Q') {
            vector<int> indexes = v_Q[i_Q];
            cout << matrix[indexes[0] - 1][indexes[1] - 1] << endl;
            i_Q++;
        }
    }

    return 0;
}
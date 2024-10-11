// Partial Pass

//有一块1x1的方形面团（不考虑面团的厚度），其口感值为0。擀面师傅要将其擀成一个N x M（纵向长N，横向宽M）的面皮。师傅的擀面手法娴熟，每次下手，要么横向擀一下（使得横向长度增加1），要么纵向擀一下（使得纵向长度增加1）。此外，当面团（皮）的大小为a x b时，往横向擀一下会使得面的口感值上升H_ab，而往纵向擀一下则会使口感值上升V_ab。
//
//现在，请你来将1x1的面团擀成N x M面皮。显然，从1x1的面团擀成N x M的面皮有多种不同的操作序列可以实现，不同操作序列下得到的最终面皮口感值也可能是不同的。请问最终得到的N x M面皮，口感值最高可为多少？
//
//输入描述
//第一行两个整数N，M，表示要擀出来面皮的大小（纵向长N，横向宽M）。
//
//接下来有N行，每行M个数。第a行第b列的数值H_ab，表示当面皮大小为a x b时，横向擀一下后，面皮口感的上升值。
//
//再接下来有N行，每行M个数。第a行第b列的数值V_ab，表示当面皮大小为a x b时，纵向擀一下后，面皮口感的上升值。
//
//（0 < N, M < 1000，0 <= H_ab, V_ab <= 1000）
//
//	输出描述
//	输出最终得到的N x M面皮的最高的口感值。
//
//	示例1 :
//输入：
//2 3
//1 2 3
//4 5 6
//11 12 13
//14 15 16
//输出：
//20
//示例2:
//输入：
//3 3
//1 0 2
//2 0 2
//2 2 0
//0 2 2
//1 2 1
//2 1 2
//输出：
//7
//提示
//【示例1解释】
//
//一共三种擀面方法：
//
//纵横横：11 + 4 + 5 = 20
//
//横纵横：1 + 12 + 5 = 18
//
//横横纵：1 + 2 + 13 = 16
//
//【示例2解释】
//
//最优擀面方法为 : 横(1) + 纵(2) + 纵(2) + 横(2) = 7

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> H_ab;
vector<vector<int>> V_ab;

int taste(int, int);

int main() {
    // Input

    //cout << "N: M: " << endl;
    cin >> N;
    cin >> M;

    //cout << "H_ab: " << endl;
    for (int i = 0; i < N; i++) {
        vector<int> r;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            r.push_back(x);
        }
        H_ab.push_back(r);
    }

    //cout << "V_ab: " << endl;
    for (int i = 0; i < N; i++) {
        vector<int> r;
        for (int j = 0; j < M; j++) {
            int x;
            cin >> x;
            r.push_back(x);
        }
        V_ab.push_back(r);
    }

    // Test Input
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << H_ab[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < M; j++) {
//            cout << V_ab[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    
    // Output
    cout << taste(N - 1, M - 1);

    return 0;
}

int taste(int r, int c) {
    if (r < 0 || c < 0) {
        return 0;
    }
    if (r == 0 && c == 0) {
        return 0;
    }
    if (r == 0) {
        return H_ab[r][c - 1] + taste(r, c - 1);
    }
    if (c == 0) {
        return V_ab[r - 1][c] + taste(r - 1, c);
    }
    return max(V_ab[r - 1][c] + taste(r - 1, c), H_ab[r][c - 1] + taste(r, c - 1));
}
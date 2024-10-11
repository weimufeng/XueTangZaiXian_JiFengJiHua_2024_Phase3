// Partial Pass

//从楼上走到楼下共有h个台阶，每一步有3种走法：走一个台阶；走两个台阶；走三个台阶。规定只能往下走，不能往上走。
//
//调皮的小明在n个台阶上撒了水，为了防止滑倒，不能踏上这n个台阶，问从楼上到楼下可走出多少种方案？
//
//输入描述
//第一行两个数字h, n，分别表示总台阶数和不能走的台阶数(1 <= n < h <= 15)
//
//	接下来n行，每行一个整数a_i，表示第a_i级台阶被撒了水不能走
//
//	输出描述
//	一个整数，表示从楼上到楼下的方案数。
//
//	示例1 :
//输入：
//5 1
//
//3
//输出：
//5
//
//提示
//第0级和第h级台阶保证不会有水

//
//  main.cpp
//  Helloworld
//
//  Created by Mufeng Wei on 10/7/24.
//

#include <iostream>
#include <vector>

using namespace std;

int h, n;
vector<int> slip(n);

void vector_minus(vector<int> v, int n) {
    for (int& x : v) {
        x -= n;
    }
}

bool detect_triple(vector<int> v) {
    for (int i = 0, j = 1, k = 2; k < v.size(); i++, j++, k++) {
        if (v[i] == v[j] - 1 && v[j] == v[k] - 1) {
            return true;
        }
    }
    return false;
}

int jump(int h, int n, vector<int> v) {
    // Base case
    if (h == 1) {
        return 1;
    }
    if (h == 2 && n == 0) {
        return 2;
    }
    if (h == 2 && n == 1) {
        return 1;
    }
    if (h == 3 && n == 0) {
        return 4;
    }
    if (h == 3 && n == 1) {
        return 2;
    }
    if (h == 3 && n == 2) {
        return 1;
    }
    if (v.size() >= 3 && detect_triple(v)) {
        return 0;
    }

    if (n == 0) {
        return jump(h - 1, 0, v) + jump(h - 2, 0, v) + jump(h - 3, 0, v);
    }

    if (v[0] == 1) {
        if (v.size() == 1) {
            return jump(h - 2, 0, v) + jump(h - 3, 0, v);
        }
        else if (v[1] == 2) {
            vector<int> s;
            s = vector<int>(v.begin() + 2, v.end());
            vector_minus(s, 3);
            return jump(h - 3, n - 2, s);
        }
        else if (v[1] == 3) {
            vector<int> s;
            s = vector<int>(v.begin() + 1, v.end());
            vector_minus(s, 2);
            return jump(h - 2, n - 1, s);
        }
        else if (v[1] == 4) {
            vector<int> s, t;
            s = vector<int>(v.begin() + 1, v.end());
            t = vector<int>(v.begin() + 1, v.end());
            vector_minus(s, 2);
            vector_minus(t, 3);
            return jump(h - 2, n - 1, s) + jump(h - 3, n - 1, t);
        }
        else {
            vector<int> s, t, u;
            s = vector<int>(v.begin() + 1, v.end());
            t = vector<int>(v.begin() + 1, v.end());
            u = vector<int>(v.begin() + 1, v.end());
            vector_minus(s, 2);
            vector_minus(t, 3);
            vector_minus(u, 4);
            return jump(h - 2, n - 1, s) + jump(h - 3, n - 1, t) + jump(h - 4, n - 1, u);
        }
    }

    if (v[0] == 2) {
        if (v.size() == 1) {
            vector<int> s = v, t = v;
            vector_minus(s, 1);
            vector_minus(t, 3);
            return jump(h - 1, n, s) + jump(h - 3, n - 1, t);
        }
        else if (v[1] == 3) {
            vector<int> s = v;
            vector_minus(s, 1);
            return jump(h - 1, n, s);
        }
        else {
            vector<int> s, t;
            vector_minus(s, 1);
            t = vector<int>(v.begin() + 1, v.end());
            vector_minus(t, 3);
            return jump(h - 1, n, s) + jump(h - 3, n - 1, t);
        }
    }

    if (v[0] == 3) {
        vector<int> s = v, t = v;
        vector_minus(s, 1);
        vector_minus(t, 2);
        return jump(h - 1, n, s) + jump(h - 2, n, t);
    }

    vector<int> s = v, t = v, u = v;
    vector_minus(s, 1);
    vector_minus(t, 2);
    vector_minus(u, 3);
    return jump(h - 1, n, s) + jump(h - 2, n, t) + jump(h - 3, n, u);
}

int main() {
    // Input
//    cout << "h: n:" << endl;
    cin >> h;
    cin >> n;
    //    cout << "slip: " << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        slip.push_back(num);
    }

    // Check slip
//    for (auto x : slip) {
//        cout << x << ' ';
//    }

//    cout << "Answer: ";
    cout << jump(h, n, slip) << endl;

    return 0;
}
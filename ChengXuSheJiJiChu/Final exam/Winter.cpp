// Pass

//土地上开了n朵名贵的花，但随着冬天的来临难以抵挡住寒风，勤劳的你需要给它们修建一个大棚让他们平安度过冬天。现在给你这n朵花的坐标，请你设计一个最小的** 正方形** 大棚，使得所有花能够平安度过冬天。（在正方形边上的花认为在大棚内部）
//
//【输入输出格式】
//
//第一行是一个整数n，表示有n朵花。
//
//接下来有n行，每行两个整数x, y表示花的坐标。
//
//输出一个整数，最小的** 正方形** 大棚的边长。
//
//输入描述
//无
//
//输出描述
//无
//
//示例1 :
//输入：
//5
//- 1 1
//2 3
//4 2
//2 2
//- 4 0
//输出：
//8
//提示
//【数据范围】
//
//80 % 的数据满足1 ≤ n ≤ 10 ^ 3, -10 ^ 9 ≤ x, y ≤ 10 ^ 9；
//
//100 % 的数据满足1 ≤ n ≤ 10 ^ 5, -10 ^ 9 ≤ x, y ≤ 10 ^ 9。

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main() {
	int n;

	vector<vector<long>> v;

	long x;

	cin >> n;

	// Fill out 2d vector
	for (int i = 0; i < n; i++) {
		vector<long> s;
		for (int j = 0; j < 2; j++) {
			cin >> x;
			s.push_back(x);
		}
		v.push_back(s);
	}

	//Print out 2d vector
	/*for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[0].size(); j++) {
			cout << v[i][j] << ' ';
		}
		cout << endl;
	}*/

	long r_min = v[0][0];
	long r_max = v[0][0];
	long c_min = v[0][1];
	long c_max = v[0][1];

	for (int i = 0; i < n; i++) {
		if (v[i][0] < r_min) {
			r_min = v[i][0];
		}
		else if (v[i][0] > r_max) {
			r_max = v[i][0];
		}

		if (v[i][1] < c_min) {
			c_min = v[i][1];
		}
		else if (v[i][1] > c_max) {
			c_max = v[i][1];
		}
	}

	long r_diff = r_max - r_min;
	long c_diff = c_max - c_min;
	cout << max(r_diff, c_diff);

	return 0;
}
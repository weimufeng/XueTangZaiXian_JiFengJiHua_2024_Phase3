// Partial Pass

//“素数（也称质数）”是指在大于1的自然数中，除了1和它本身以外没有其他因数的自然数。如果两个素数之间没有其他素数，则称这两个素数为一对** “相邻素数”** 。例如，2和3是一对“相邻素数”，3和7则不是“相邻素数”，因为在3和7之间有素数5。
//
//请你编写一个程序，对于给定两个数字L和U所限定的区间，你需要
//
//（1）找到一对“相邻素数”C1和C2（L ≤ C1 < C2 ≤ U），使得C2 - C1最小。如果在这个区间中有多对“相邻素数”都是间距最小的，则选择其中C1 + C2最小的一对。
//
//	（2）找到一对“相邻素数”D1和D2（L ≤ D1 < D2 ≤ U），使得D2 - D1最大。如果在这个区间中有多对“相邻素数”都是间距最大的，则选择其中D1 + D2最小的一对。
//
//	注意：在指定区间内可能没有“相邻素数”，此时请按题目要求输出。
//
//	输入描述
//	输入两个正整数L和U，且L < U。
//
//	输出描述
//	输出包括两行，第一行为区间内间距最小的“相邻素数”（数值小的在前，数值大的在后，中间为空格），第二行为区间内间距最大的“相邻素数”（数值小的在前，数值大的在后，中间为空格）。
//
//	若区间内没有相邻素数，则仅输出 - 1。
//
//	【样例输入1】
//
//	2 17
//
//	【样例输出1】
//
//	2 3
//
//	7 11
//
//	示例1:
//输入：
//14 17
//输出：
//- 1
//【数据范围】
//& emsp; &emsp; 50 % 的数据满足1 ≤ L < U ≤ 10 ^ 5；
//	& emsp; &emsp; 80 % 的数据满足1 ≤ L < U ≤ 10 ^ 6；
//	& emsp; &emsp; 100 % 的数据满足1 ≤ L < U ≤ 10 ^ 9, 且(U - L) ≤ 10 ^ 6；

#include <iostream>
#include <vector>

using namespace std;

bool is_prime(long);
vector<long> find_primes(long, long);
vector<long> find_closest_neighbor(vector<long>);
vector<long> find_furthest_neighbor(vector<long>);

int main() {
	//Input
	long L, U;
	cin >> L;
	cin >> U;

	vector<long> primes = find_primes(L, U);

	// Test find_primes
	/*for (int i = 0; i < primes.size(); i++) {
		cout << primes[i] << ' ';
	}
	cout << endl;*/

	if (primes.size() <= 1) {
		cout << -1 << endl;
	}
	else {
		vector<long> res_close = find_closest_neighbor(primes);
		for (long i = 0; i < res_close.size(); i++) {
			cout << res_close[i] << ' ';
		}
		cout << endl;

		vector<long> res_far = find_furthest_neighbor(primes);
		for (long i = 0; i < res_far.size(); i++) {
			cout << res_far[i] << ' ';
		}
	}

	return 0;
}

bool is_prime(long n) {
	if (n <= 1) {
		return false;
	}
	for (long i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

vector<long> find_primes(long l, long u) {
	vector<long> primes;
	for (long i = l; i <= u; i++) {
		if (is_prime(i)) {
			primes.push_back(i);
		}
	}
	return primes;
}

vector<long> find_closest_neighbor(vector<long> p) {
	long min_distance = p[1] - p[0];
	long index = 1;
	for (long i = 1; i < p.size(); i++) {
		if (p[i] - p[i - 1] < min_distance) {
			min_distance = p[i] - p[i - 1];
			index = i;
		}
	}

	vector<long> res;
	res.push_back(p[index - 1]);
	res.push_back(p[index]);
	return res;
}

vector<long> find_furthest_neighbor(vector<long> p) {
	long max_distance = p[1] - p[0];
	long index = 1;
	for (long i = 1; i < p.size(); i++) {
		if (p[i] - p[i - 1] > max_distance) {
			max_distance = p[i] - p[i - 1];
			index = i;
		}
	}

	vector<long> res;
	res.push_back(p[index - 1]);
	res.push_back(p[index]);
	return res;
}

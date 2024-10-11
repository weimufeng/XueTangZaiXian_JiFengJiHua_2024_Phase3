// Pass

//设有一个字符串S，它全部由小写字母组成。
//
//现在，老师想知道，字符串S从下标L到下标R的区间中，不同的小写字母各出现了多少次。（注意：字符串下标从0开始）
//
//老师一共会向你询问Q次，每次都会告诉你区间的起始下标L和终止下标R。请你回答每次询问。
//
//输入描述
//第一行一个字符串S（长度 <= 1000）
//
//第二行为一个整数Q（Q <= 100）
//
//接下来有Q行，每行两个整数L和R。（0 <= L, R < **字符串S的长度** ））
//
//	输出描述
//	对于每次询问，输出一行结果，表示每种小写字母出现的次数。
//
//	输出格式为”<小写字母> : <出现次数>”，请按从a到z的次序，输出每种小写字母，以及对应出现的次数。** 用英文冒号分隔字母和次数，中间没有空格。**
//
//	每两种小写字母的结果之间用一个空格隔开。
//
//	忽略出现次数为0的小写字母。
//
//	示例1 :
//输入：
//abcdefgaaa
//2
//0 0
//1 8
//输出：
//a : 1
//a : 2 b : 1 c : 1 d : 1 e : 1 f : 1 g : 1

#include <iostream>
#include <vector>

using namespace std;

int main() {
	// Declaration
	string S;
	int Q;
	vector<vector<int>> v;

	// Input
	cin >> S;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		vector<int> row;
		int x;
		for (int j = 0; j < 2; j++) {
			cin >> x;
			row.push_back(x);
		}
		v.push_back(row);
	}

	// Test v
	/*for (int i = 0; i < Q; i++) {
		cout << v[i][0] << ' ' << v[i][1] << endl;
	}

	cout << S << endl;*/

	/*vector<int> count(26, 0);
	for (int i = 0; i < count.size(); i++) {
		cout << count[i] << ' ';
	}*/

	//Output
	for (int i = 0; i < Q; i++) {
		vector<int> count(26, 0);
		for (int j = v[i][0]; j <= v[i][1]; j++) {
			int diff = S[j] - 'a';
			count[diff] += 1;
		}
		for (int k = 0; k < count.size(); k++) {
			if (count[k] != 0) {
				char c;
				c = 'a' + k;
				cout << c << ':' << count[k] << ' ';
			}
		}
		cout << endl;
	}

	return 0;
}
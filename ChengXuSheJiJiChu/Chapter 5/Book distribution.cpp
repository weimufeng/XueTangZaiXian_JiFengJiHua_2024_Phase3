// Partial Pass

//现在有N本书，准备分给N个人。每个人的阅读兴趣，用一个二维数组like[i][j]加以描述。
//
//若 like[i][j] = 1 ，则表示第i个人喜欢第j本书；反之，若 like[i][j] = 0 ，则表示第i个人不喜欢第j本书。
//
//现在已知like数组，请写一个程序，输出所有的分书方案，让人人皆大欢喜。
//
//输入描述
//第一行有一个整数N。(N <= 5)
//
//之后有N行，每i行有N个数a_ij，取值为0或1，表示like数组，即第i个人是否喜欢第j本书。0表示不喜欢，1表示喜欢。
//
//输出描述
//输出多行。
//
//每行输出一种分书方案，按顺序输出1~N每个书分给对应的人的编号。
//
//所有分书方案，按字典序从小到大的顺序输出。
//
//示例1 :
//输入：
//5
//
//0 0 1 1 0
//
//1 1 0 0 1
//
//0 1 1 0 1
//
//0 0 0 1 0
//
//0 1 0 0 1
//输出：
//
//2 3 1 4 5
//
//2 5 1 4 3

#include <iostream>

using namespace std;

int N;
int** matrix = new int* [N];
int* take = new int[N];
bool* assigned = new bool[N];
int* books = new int[N];
bool* people_assigned = new bool[N];
//int take[5];
//bool assigned[5];

void Try(int id) {
    // Base case
    if (id == 5) {
        for (int i = 0; i < N; i++) {
            cout << take[i] << ' ';
        }
        cout << endl;
        return;
    }

    for (int book = 0; book < N; book++) {
        if (matrix[id][book] == 1 && !assigned[book]) {
            take[id] = book;
            assigned[book] = true;
            Try(id + 1);
            assigned[book] = false;
        }
    }
}

void Try1(int book) {
    // Base case
    if (book == 5) {
        for (int i = 0; i < N; i++) {
            cout << books[i] + 1 << ' ';
        }
        cout << endl;
        return;
    }

    for (int people = 0; people < N; people++) {
        if (matrix[people][book] == 1 && !people_assigned[people]) {
            books[book] = people;
            people_assigned[people] = true;
            Try1(book + 1);
            people_assigned[people] = false;
        }
    }
}

int main() {
    cin >> N;

    // Allocate memory for each row
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }

    // Fill the matrix with values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    // Fill the assigned with false
    for (int i = 0; i < N; i++) {
        assigned[i] = false;
    }

    // Fill the assigned with false
    for (int i = 0; i < N; i++) {
        people_assigned[i] = false;
    }

    // Print the matrix
    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    //Try(0);
    Try1(0);

    // Deallocate memory
    /*for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;*/

    //delete[] take;
    //delete[] assigned;

    return 0;
}
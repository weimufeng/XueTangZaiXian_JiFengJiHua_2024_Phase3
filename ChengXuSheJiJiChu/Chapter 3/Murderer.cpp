// Pass

//巴斯维克命案抓住了六个嫌疑犯，他们的口供如下：
//
//A：我不是罪犯
//
//B：A、C中有一个是罪犯
//
//C：A和B说了假话
//
//D：C和F说了假话
//
//E：其他五个人中，只有A和D说了真话
//
//F：我是罪犯
//
//他们中只有一半说了真话，凶手只有一个。
//
//本题答案不唯一，请编程找出所有可能的凶手。
//
//输入描述
//无
//
//输出描述
//将所有答案依字母顺序输出。每行表示为一个答案。
//
//示例1 :
//输入：
//无
//输出：
//A
//
//D
//
//E

#include <iostream>
#include <cmath>

int main() {
    for (int i = 1; i < (1 << 6); i = i << 1) {
        int A = (i >> 5) & 1;
        int B = (i >> 4) & 1;
        int C = (i >> 3) & 1;
        int D = (i >> 2) & 1;
        int E = (i >> 1) & 1;
        int F = i & 1;

        // Boolean conditions
        bool b1 = (A == 0);
        bool b2 = (A == 1) || (C == 1);
        bool b3 = !b1 && !b2;
        bool b6 = (F == 1);
        bool b4 = !b3 && !b6;
        bool b5 = b1 && b4 && !b2 && !b3 && !b6;

        if ((b1 + b2 + b3 + b4 + b5 + b6) == 3) {
            for (int j = 0; j < 6; j++) {
                if (i == static_cast<int>(pow(2, j))) {
                    char murderer = 'A' + j;
                    std::cout << murderer << std::endl;
                }
            }
        }
    }
    return 0;
}

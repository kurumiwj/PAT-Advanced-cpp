//Scientific Notation
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
    string s;
    int i = 0;
    cin >> s;
    while (s[i] != 'E')i++;
    string a = s.substr(1, i - 1);     //截取E前面的部分
    int n = stoi(s.substr(i + 1));      //截取E后面的部分
    if (s[0] == '-')printf("-");        //如果输入的是负数则先输出负号
    if (n < 0) {        //如果E后面部分是负数则说明整体缩小，小数点往前移
        cout << "0.";
        for (int j = 0; j < abs(n) - 1; j++)cout << '0';
        for (int j = 0; j < a.length(); j++) {
            if (a[j] != '.') {
                cout << a[j];
            }
        }
    } else {
        cout << a[0];
        int cnt, j;
        for (j = 2, cnt = 0; j < a.length() && cnt < n; j++, cnt++) {       //从小数点后一项开始输出直到输到末尾或者n位输完
            cout << a[j];
        }
        if (j == a.length()) {      //如果a已经全部输完但是还没有结束，剩下补0
            for (int k = 0; k < n - cnt; k++)printf("0");
        } else {        //如果n已经全部输完但是a还没到底，则先输出一个小数点接着输出剩下内容
            printf(".");
            for (int k = j; k < a.length(); k++)cout << a[k];
        }
    }
    system("pause");
    return 0;
}
//Mars Numbers
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;
string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string s2[12] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void func1(int n);

void func2(string s);

int main() {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        if (isdigit(s[0]))func1(stoi(s));
        else func2(s);
        printf("%s", i < n - 1 ? "\n" : "");
    }
    system("pause");
    return 0;
}

void func1(int n) {     //从数字转成火星文
    if (n / 13) {
        cout << s2[n / 13 - 1];
        if (n % 13)printf(" "), cout << s1[n % 13];
        else return;
    } else cout << s1[n % 13];
}

void func2(string s) {       //从火星文转成数字
    if (s != s1[0]) {
        int len = s.length();
        if (len > 3) {
            string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
            int num = 0;
            for (int i = 0; i < 12; i++) if (s2[i] == temp1)num = 13 * (i + 1);
            for (int i = 0; i < 13; i++) if (s1[i] == temp2)num += i;
            printf("%d", num);
        } else {
            for (int i = 0; i < 13; i++) if (s1[i] == s)printf("%d", i);
            for (int i = 0; i < 12; i++) if (s2[i] == s)printf("%d", (i + 1) * 13);
        }
    } else printf("0");
}
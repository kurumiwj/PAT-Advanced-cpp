//Look-and-say Sequence
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

int main() {
    string s;
    int n, j;
    cin >> s >> n;
    for (int cnt = 1; cnt < n; cnt++) {
        string t;
        int x = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == s[i + 1])x++;       //统计相同字符出现的个数
            else t += s[i] + to_string(x), x = 1;
        }
        s = t;
    }
    cout << s << endl;
    system("pause");
    return 0;
}
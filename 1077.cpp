//Kuchiguse
//思路：没输入一个字符串都先反转然后与之后输入的比较
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
    int n;
    scanf("%d\n", &n);
    string ans;     //用于存放反转后相同的前n个字符
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        int lens = s.length();      //获取输入字符串的长度
        reverse(s.begin(), s.end());        //反转输入的字符串
        if (i == 0) {
            ans = s;        //首先获取第一个输入的字符串的反转
            continue;
        } else {
            int lenans = ans.length();
            int minlen = min(lens, lenans);
            for (int j = 0; j < minlen; j++) {
                if (ans[j] != s[j]) {       //如果输入的字符串和ans中第j个不同则截取ans中前j个字符串
                    ans = ans.substr(0, j);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0)printf("nai");
    cout << ans << endl;
    system("pause");
    return 0;
}
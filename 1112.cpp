//Stucked Keyboard
/*注意点：不是所有出现连续k次的字符都是坏键！！
 * 先统计所有出现连续k次的字符，将他们存放在一个集合里，然后再统计集合里的这些字符是否有单独出现或者仅出现连续[2,k-1]次的情况
*/
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
/*以下为原创但总有两个测试点过不去
int main() {
    int k, cnt = 1;
    scanf("%d\n", &k);
    string str;
    set<char> s;        //存放所有出现连续三次的字母(有可能是坏键也有可能不是)
    map<char, bool> m;      //用来保存好键，如果m里key为true的一定是好键
    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if ((str[i + 1] != str[i]) && cnt % k) {
            if (!m[str[i]])m[str[i]] = true, cnt = 1;   //如果字符串下一项与该项不等并且该项出现次数不是k的整数倍则一定是好键
        } else if ((str[i + 1] != str[i]) && cnt % k == 0)s.insert(str[i]), cnt = 1; //如果下一项与该项不等并且该项出现次数是k的整数倍，则有可能是坏键
        else if (str[i + 1] == str[i]) cnt++;   //如果下一项与该项相等则cnt加1
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        if (m[*it] != 1)cout << *it;
    }
    printf("\n");
    for (int i = 0; i < str.length();) {
        if (m[str[i]] == 1)cout << str[i], i++;
        else cout << str[i], i += k;
    }
    return 0;
}
 */
//下面是柳神的代码
#include <iostream>
#include <map>
#include <cstdio>
#include <set>

using namespace std;
bool sureNoBroken[256];

int main() {
    int k, cnt = 1;
    scanf("%d", &k);
    string s;
    cin >> s;
    map<char, bool> m;
    set<char> printed;
    char pre = '#';
    s = s + '#';
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == pre) {
            cnt++;
        } else {
            if (cnt % k != 0) {
                sureNoBroken[pre] = true;
            }
            cnt = 1;
        }
        if (i != s.length() - 1) m[s[i]] = (cnt % k == 0);
        pre = s[i];
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (sureNoBroken[s[i]] == true)
            m[s[i]] = false;
    }
    for (int i = 0; i < s.length() - 1; i++) {
        if (m[s[i]] && printed.find(s[i]) == printed.end()) {
            printf("%c", s[i]);
            printed.insert(s[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < s.length() - 1; i++) {
        printf("%c", s[i]);
        if (m[s[i]])
            i = i + k - 1;
    }
    return 0;
}
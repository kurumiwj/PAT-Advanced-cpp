//Raffle for Weibo Followers
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
    set<string> winner;      //存放获奖名单，无重复
    int m, n, s;
    scanf("%d %d %d", &m, &n, &s);
    string name[m];
    if (s > m)printf("Keep going...");
    else {
        for (int i = 0; i < m; i++) {
            cin >> name[i];
            if (i + 1 == s) winner.insert(name[i]);
        }
        cout << name[s - 1] << endl;
        for (int i = s - 1 + n; i < m; i += n) {
            c:
            if (winner.find(name[i]) == winner.end())
                winner.insert(name[i]), cout << name[i] << endl;//如果获奖名单里没有此人则插入此人名字
            else {
                i++;
                goto c;
            }
        }
    }
    system("pause");
    return 0;
}
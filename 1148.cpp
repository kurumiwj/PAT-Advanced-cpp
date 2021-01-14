//Werewolf - Simple Version
/*题意：n名玩家中有2人扮演狼人角色，有2人说的不是实话，有狼人撒谎但并不是所有狼人都在撒谎。找出扮演狼人角色的是哪几号玩家，如果有解，在一行中按递增顺序输出2个狼人的编号；如果解不唯一，则输出最小序列解；若无解则输出no
 * solution.
 * 分析：每个人说的数字保存在v数组中，i从1～ｎ、j从i+1～ｎ遍历，分别假设i和j是狼人，a数组表示该人是狼人还是好人，等于1表示是好人，等于-1表示是狼人。k从1～n分别判断k所说的话是真是假，k说的话和真是情况不同，
 * (即v[k]*a[abs(v[k])]<0)则表示k在说谎，则将k放在lie数组中；遍历完成后判断lie数组，如果说谎人数等于2并且这两个说谎的人一个是好人一个是狼人(即a[lie[0]]+a[lie[1]]==0)
 * 表示满足题意，此时输出i和j并return，否则最后的时候输出No Solution
 * PS:此题想法较为复杂，自己做估计得一个小时起步，在此借用柳神大大更为精简的做法，掌握思想
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

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)scanf("%d", &v[i]);
    for (int i = 1; i <= n; i++) {      //假设i和j是狼人
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++) {
                if (v[k] * a[abs(v[k])] < 0)lie.push_back(k);       //如果k说的和实际情况不一致则说明k在说谎
            }
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                printf("%d %d", i, j);
                return 0;
            }
        }
    }
    printf("No Solution");
    system("pause");
    return 0;
}
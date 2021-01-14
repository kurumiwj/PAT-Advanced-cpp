//N Queens Puzzle
//column和row只要看有没有相同数字即可，对角线只需看两数字之差以及他们的下标之差是否相等
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
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int n, j;
        scanf("%d", &n);
        vector<int> a(n);
        int flag = 1;
        for (j = 0; j < n; j++) {
            cin >> a[j];
            for (int l = 0; l < j; l++) {
                if (a[l] == a[j] || abs(a[j] - a[l]) == abs(j - l)) {
                    flag = 0;
                    break;
                }
            }
        }
        printf("%s\n", flag == 1 ? "YES" : "NO");
    }
    system("pause");
    return 0;
}
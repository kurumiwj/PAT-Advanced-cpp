//Friend Numbers
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
    set<int> s;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int sum = 0, m;
        scanf("%d", &m);
        for (int j = 0; m > 0; j++) {
            sum = sum + m % 10;
            m /= 10;
        }
        s.insert(sum);
    }
    printf("%d\n", s.size());
    for (auto it = s.begin(); it != s.end(); it++) {
        printf("%s%d", it != s.begin() ? " " : "", *it);
    }
    system("pause");
    return 0;
}
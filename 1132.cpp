//Cut Integer
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
    for (int i = 0; i < n; i++) {
        string z;
        cin >> z;
        int len = z.length();
        string z1 = z.substr(0, len / 2);
        string z2 = z.substr(len / 2);
        if (stoll(z1) * stoll(z2)) {
            if (stoll(z) % (stoll(z1) * stoll(z2)) == 0)printf("Yes\n");
            else printf("No\n");
        } else printf("No\n");
    }
    system("pause");
    return 0;
}
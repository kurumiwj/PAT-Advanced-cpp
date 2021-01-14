//A+B and C
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
    long long a, b, c, sum;
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            printf("Case #%d: true\n", i + 1);
        } else if (a < 0 && b < 0 && sum >= 0) {
            printf("Case #%d: false\n", i + 1);
        } else {
            printf("Case #%d: %s\n", i + 1, sum > c ? "true" : "false");
        }
    }
    system("pause");
    return 0;
}
//Come on! Let's C
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

int isPrime(int n);

int main() {
    int n, t, k;
    scanf("%d", &n);
    map<int, int> m;
    set<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        m[t] = i + 1;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &t);
        printf("%04d: ", t);
        if (m.count(t) == 0) {
            printf("Are you kidding?\n");
            continue;
        }
        if (s.find(t) == s.end()) {
            s.insert(t);
        } else if (s.find(t) != s.end()) {
            printf("Checked\n");
            continue;
        }
        if (m[t] == 1) {
            printf("Mystery Award\n");
        } else if (isPrime(m[t])) {
            printf("Minion\n");
        } else {
            printf("Chocolate\n");
        }
    }
    system("pause");
    return 0;
}

int isPrime(int n) {
    int s = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            s = 0;
            break;
        }
    }
    return s;
}
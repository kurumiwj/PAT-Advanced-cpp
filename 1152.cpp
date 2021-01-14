//Google Recruitment
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

bool isPrime(int n);

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    for (int i = 0; i <= n - k; i++) {
        string s1 = s.substr(i, k);
        int a = stoi(s1);
        if (isPrime(a)) {
            cout << s1;
            return 0;
        }
    }
    printf("404");
    return 0;
}

bool isPrime(int n) {
    if (n == 0 || n == 1)return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)return false;
    }
    return true;
}
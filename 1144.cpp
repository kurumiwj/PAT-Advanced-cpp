//The Missing Number
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
    map<int, int> num;
    int n, a, i = 1;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
        scanf("%d", &a);
        num[a]++;
    }
    while (i) {
        if (num[i] == 0) {
            printf("%d", i);
            break;
        }
        i++;
    }
    system("pause");
    return 0;
}
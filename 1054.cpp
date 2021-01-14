//The Dominant Color
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    map<int, int> color;
    int m, n, half, temp;
    scanf("%d %d", &m, &n);
    half = m * n / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &temp);
            color[temp]++;
            if (color[temp] > half) {
                printf("%d", temp);
                break;
            }
        }
    }
    system("pause");
    return 0;
}
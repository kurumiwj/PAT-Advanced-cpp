//Dating
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<char> s;     //如果这里定义大小，下面可以用数组形式，否则只能用push_back或者resize分配大小
    int minute, hour, i = 0, j = 0;
    string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G')) {
            s.push_back(a[i]);
            j++;
            break;
        }
        i++;
    }
    i++;
    while (i < a.length() && i < b.length()) {
        if (a[i] == b[i] && ((a[i] >= 'A' && a[i] <= 'N') || isdigit(a[i]))) {
            s.push_back(a[i]);
            break;
        }
        i++;
    }
    hour = isdigit(s[j]) ? s[j] - '0' : s[j] - 'A' + 10;
    i = 0;
    while (i < c.length() && i < d.length()) {
        if (c[i] == d[i] && isalpha(c[i])) {
            minute = i;
            break;
        }
        i++;
    }
    cout << week[s[0] - 'A'] << " ";
    printf("%02d:%02d", hour, minute);
    system("pause");
    return 0;
}
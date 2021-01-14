//The Black Hole of Numbers
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

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    string a, b, c;
    int result;
    cin >> a;
    a.insert(0, 4 - a.length(), '0');       //不满四位数前面补0
    do {
        b = a, c = a;
        sort(b.begin(), b.end());       //默认从小到大排序
        sort(c.begin(), c.end(), cmp);        //从大到小排序
        result = stoi(c) - stoi(b);
        a = to_string(result);
        a.insert(0, 4 - a.length(), '0');
        cout << c << " - " << b << " = " << a << endl;
    } while (result != 0 && result != 6174);
    system("pause");
    return 0;
}
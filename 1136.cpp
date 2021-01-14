//A Delayed Palindrome
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

string str_rev(string s);

int main() {
    string s;
    cin >> s;
    if (s == str_rev(s)) {
        cout << s << " is a palindromic number.";
        return 0;
    }
    int j;
    for (j = 0; j < 10; j++) {
        string s2 = str_rev(s);
        string s3 = s;
        int a = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            s3[i] = (char) ((s[i] - '0' + s2[i] - '0' + a) % 10 + '0');
            a = (s[i] - '0' + s2[i] - '0' + a) / 10;
        }
        if (a > 0)s3 = '1' + s3;
        cout << s << " + " << s2 << " = " << s3 << endl;
        if (str_rev(s3) == s3) {
            cout << s3 << " is a palindromic number.";
            return 0;
        }
        s = s3;
    }
    if (j == 10)printf("Not found in 10 iterations.");
    system("pause");
    return 0;
}

string str_rev(string s) {
    reverse(s.begin(), s.end());
    return s;
}
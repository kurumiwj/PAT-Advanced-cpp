//Broken Keyboard
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
    string s1, s2, ans;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.length(); i++) {
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos) {
            ans += toupper(s1[i]);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
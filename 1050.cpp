//String Subtraction
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    bool flag[256] = {false};
    for (int i = 0; i < s2.length(); i++) {
        flag[s2[i]] = true;
    }
    for (int i = 0; i < 256; i++) {
        cout << flag[i];
    }
    for (int i = 0; i < s1.length(); i++) {
        if (!flag[s1[i]]) {
            printf("%c", s1[i]);
        }
    }
    system("pause");
    return 0;
}
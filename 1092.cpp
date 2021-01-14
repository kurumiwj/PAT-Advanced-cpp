//To Buy or Not to Buy
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
    string a, b;
    int cnt = 0;
    getline(cin, a);
    getline(cin, b);
    map<char, int> book;        //存放字符串中各字符出现的次数
    for (int i = 0; i < a.length(); i++) {
        book[a[i]]++;
    }
    for (int i = 0; i < b.length(); i++) {
        if (book[b[i]] > 0) {
            book[b[i]]--;
        } else {
            cnt++;
        }
    }
    if (cnt == 0)printf("Yes "), cout << a.length() - b.length();
    else printf("No %d", cnt);
    system("pause");
    return 0;
}
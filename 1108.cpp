//Finding Average
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

int main() {
    int n, cnt = 0;
    double temp, sum = 0.0;
    char a[20], b[20];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf", temp);
        int flag = 1;
        for (int j = 0; j < strlen(a); j++) {
            if (a[j] != b[j])flag = 0;
        }
        if (flag == 0 || fabs(temp) > 1000) printf("ERROR: %s is not a legal number\n", a);
        else sum += temp, cnt++;
    }
    if (cnt > 0) printf("The average of %d number%s is %.2lf", cnt, cnt == 1 ? "" : "s", sum / cnt);
    else printf("The average of 0 numbers is Undefined");
    system("pause");
    return 0;
}
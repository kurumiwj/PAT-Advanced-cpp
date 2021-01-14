//Sum of Number Segments
/*思路：将数列中的每个数字读取到temp中，假设选取的片段中包括temp，且这个片段的首尾指针分别为p和q，那么对于p，有i种选择，即12...i,对于q，有n+1-i种选择，即i,i+1,...n,
 * 所以p和q组合形成的首尾片段有i*(n+1-i)种，因为每个里面都会出现temp，所以temp引起的总和为temp*i*(n+1-i)。
 * 遍历完所有数字，将每个temp引起的总和都累加到sum中，最后输出sum的值
 * PS:该题如果用排列组合可能会超范围
*/
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
    int n;
    double sum = 0.0, temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &temp);
        sum = sum + temp * i * (n + 1 - i);
    }
    printf("%.2lf", sum);
    system("pause");
    return 0;
}
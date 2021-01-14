//Consecutive Factors
/*思路：如果只有⼀个因⼦，那么这个数只能为1或者质数；
 *      在有两个及以上的数连乘中，因数的最大上限为sqrt(n)，因此不断构造连乘，看连乘的积是否是n的因数，如果是，则看这部分连乘的数的个数是否比已记录的多；
 *      用变量first记录连乘的第一个数字，赋初值为0，如果在寻找n的因数过程中，first没有改变，那么就表明n是1或者是一个质数*/
#include <iostream>
#include <string>
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
    long long n, first = 0, i, j, maxn, len = 0;
    scanf("%lld", &n);
    maxn = sqrt(n);
    for (i = 2; i <= maxn; i++) {
        int temp = 1;
        for (j = i; j <= maxn; j++) {
            temp *= j;
            if (n % temp != 0)break;
        }
        if (j - i > len)len = j - i, first = i;     //刷新最长因数记录以及起始点
    }
    if (first == 0)printf("1\n%lld", n);      //说明该数是质数
    else {
        printf("%lld\n", len);
        for (i = 0; i < len; i++) {
            printf("%lld%s", first + i, i < len - 1 ? "*" : "");
        }
    }
    system("pause");
    return 0;
}
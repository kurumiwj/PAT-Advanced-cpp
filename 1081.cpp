//Rational Sum
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

long long gcd(long long a, long long b);        //最大公约数

int main() {
    long long a, b, suma = 0, sumb = 1, n, gcdvalue;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld/%lld", &a, &b);
        gcdvalue = gcd(a, b);       //先对分数进行化简
        a = a / gcdvalue;
        b = b / gcdvalue;
        suma = a * sumb + b * suma;     //所求和的分子
        sumb = sumb * b;        //所求和的分母
        gcdvalue = gcd(suma, sumb);     //所求和的最大公约数
        sumb /= gcdvalue;
        suma /= gcdvalue;
    }
    long long integer = suma / sumb;        //所求和的整数部分
    suma = suma - (integer * sumb);     //所求和的分数部分的分子
    if (integer != 0) {
        printf("%lld%s", integer, suma != 0 ? " " : "");
    }
    if (suma != 0)printf("%lld/%lld", suma, sumb);
    if (integer == 0 && suma == 0)printf("0");
    system("pause");
    return 0;
}

long long gcd(long long a, long long b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}
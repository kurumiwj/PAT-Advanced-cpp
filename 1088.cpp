//Rational Arithmetic
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
void func(long long m, long long n);

int main() {
    long long a1, b1, a2, b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);       //题目已经说明两个分数都是最简形式所以不用再化简
    //加法
    func(a1, b1), printf(" + "), func(a2, b2), printf(" = "), func(a1 * b2 + a2 * b1, b1 * b2);
    printf("\n");
    //减法
    func(a1, b1), printf(" - "), func(a2, b2), printf(" = "), func(a1 * b2 - a2 * b1, b1 * b2);
    printf("\n");
    //乘法
    func(a1, b1), printf(" * "), func(a2, b2), printf(" = "), func(a1 * a2, b1 * b2);
    printf("\n");
    //除法(题目中已经说明给出的两个分数分母都不为0,只需考虑最后结果分母是否有0即可)
    func(a1, b1), printf(" / "), func(a2, b2), printf(" = "), func(a1 * b2, b1 * a2);
    printf("\n");
    system("pause");
    return 0;
}

long long gcd(long long a, long long b) {
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void func(long long m, long long n) {
    if (m * n == 0) {
        printf("%s", n == 0 ? "Inf" : "0");
        return;
    }
    bool flag = ((m > 0 && n < 0) || (m < 0 && n > 0));
    m = abs(m), n = abs(n);
    long long integer = m / n, gcdvalue;
    printf("%s", flag ? "(-" : "");
    if (integer != 0)printf("%lld", integer);
    if (m % n == 0) {     //如果分子刚好可以整除分母则只有整数部分没有分数部分
        printf("%s", flag ? ")" : "");
        return;
    }
    if (integer != 0)printf(" ");       //如果没有整数部分则不留空只输出分数部分
    m -= integer * n;
    gcdvalue = gcd(m, n);
    m /= gcdvalue, n /= gcdvalue;
    printf("%lld/%lld%s", m, n, flag ? ")" : "");
}
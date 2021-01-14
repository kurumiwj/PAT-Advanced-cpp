//Reversible Primes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum {
    false, true
} bool;

int decimal(int x, int d, bool n);

bool Prime(int x);

int reverse(int x);

int main() {
    int m = 0, n = 10, x;
    while (m >= 0) {
        scanf("%d", &m);
        if (m < 0) {
            break;
        }
        scanf("%d", &n);
        x = decimal(m, n, 1);
        printf("%s", Prime(m) == true && Prime(decimal(reverse(x), n, 0)) == true ? "Yes\n" : "No\n");
    }
    system("pause");
    return 0;
}

int decimal(int x, int d, bool n) {         //n=1为十进制转换成d进制，否则为d进制转换成十进制
    int a[50] = {-1};
    int i = 0, s = 0, k1, k2;
    if (n == 1)k1 = d, k2 = 10;
    else k1 = 10, k2 = d;
    while (x > 0) {
        a[i] = x % k1;
        x /= k1;
        i++;
    }
    for (i = i - 1; i >= 0; i--) {
        s = s * k2 + a[i];
    }
    return s;
}

bool Prime(int x) {          //判断是否为素数
    if (x <= 1)return false;
    int i;
    for (i = 2; i <= (int) sqrt(x); i++) {
        if (x % i == 0)return false;
    }
    return true;
}

int reverse(int x) {            //整数反转
    int t = x, i = 0, s = 0, j;
    int a[10] = {-1};
    while (t > 0) {
        a[i] = t % 10;
        t /= 10;
        i++;
    }
    j = i - 1;
    for (i = 0; i <= j; i++) {
        s = s * 10 + a[i];
    }
    return s;
}
//A+B Format
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c, m, n, o;
    scanf("%d %d", &a, &b);
    if (abs(a) <= 1000000 && abs(b) <= 1000000) {
        c = a + b;
        if (abs(c) >= 1000000) {
            m = c / 1000000;
            printf("%d,", m);
            c %= 1000000;
            n = abs(c) / 1000;
            if (n == 0) {
                printf("000,");
            } else if (n < 10) {
                printf("00%d,", n);
            } else if (n < 100) {
                printf("0%d,", n);
            } else {
                printf("%d,", n);
            }
            o = abs(c) % 1000;
            if (o == 0) {
                printf("000\n");
            } else if (o < 10) {
                printf("00%d\n", o);
            } else if (o < 100) {
                printf("0%d\n", o);
            } else {
                printf("%d\n", o);
            }
        } else if (abs(c) < 1000) {
            printf("%d\n", c);
        } else {
            m = c / 1000;
            n = abs(c) % 1000;
            if (n == 0) {
                printf("%d,000\n", m);
            } else if (n < 10) {
                printf("%d,00%d\n", m, n);
            } else if (n < 100) {
                printf("%d,0%d\n", m, n);
            } else {
                printf("%d,%d\n", m, n);
            }
        }
    }
    system("pause");
    return 0;
}
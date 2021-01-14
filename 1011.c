//World Cup Betting
#include <stdio.h>
#include <stdlib.h>

int max(double a, double b, double c);

int main() {
    double a[3][3], s = 1;
    int i, j, t;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++) {
        t = max(a[i][0], a[i][1], a[i][2]);
        if (t == 0) {
            printf("W ");
        } else if (t == 1) {
            printf("T ");
        } else {
            printf("L ");
        }
        s = s * a[i][t];
    }
    printf("%.2lf", (s * 0.65 - 1) * 2);
    system("pause");
    return 0;
}

int max(double a, double b, double c) {
    int t;
    if (a > b && a > c) {
        t = 0;
    }
    if (b > a && b > c) {
        t = 1;
    }
    if (c > a && c > b) {
        t = 2;
    }
    return t;
}
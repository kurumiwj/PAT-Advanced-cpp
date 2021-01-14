//1003 Emergency
#include <stdio.h>
#include <stdlib.h>

int main() {
    int k1, k2, i, j, min, count = 0;
    scanf("%d", &k1);
    double a[2 * k1];
    for (i = 0; i < 2 * k1; i++) {
        scanf("%lf", &a[i]);
    }
    scanf("%d", &k2);
    double b[2 * k2];
    for (j = 0; j < 2 * k2; j++) {
        scanf("%lf", &b[j]);
    }
    if (k1 < k2) {
        min = 2 * k1;
    } else {
        min = 2 * k2;
    }
    count = k1 + k2;
    for (i = 0; i < 2 * k1; i += 2) {
        for (j = 0; j < 2 * k2; j += 2) {
            if (a[i] == b[j]) {
                count--;
                break;
            }
        }
    }
    i = 0;
    j = 0;
    printf("%d ", count);
    while (i < min && j < min) {
        if (a[i] == b[j]) {
            printf("%d%s", (int) a[i], i < min ? " " : "");
            printf("%.1lf%s", a[i + 1] + b[j + 1], i < min - 2 ? " " : "");
            i += 2;
            j += 2;
        } else if (a[i] < b[j]) {
            printf("%d %.1lf%s", (int) b[j], b[j + 1], j < min ? " " : "");
            j += 2;
        } else if (a[i] > b[j]) {
            printf("%d %.1lf%s", (int) a[i], a[i + 1], i < min ? " " : "");
            i += 2;
        }
    }
    if (i == j) {
        printf(" ");
    }
    if (j >= min) {
        while (i < 2 * k1) {
            printf("%d %.1lf%s", (int) a[i], a[i + 1], i < 2 * k1 - 2 ? " " : "");
            i += 2;
        }
    }
    if (i >= min) {
        while (j < 2 * k2) {
            printf("%d %.1lf%s", (int) b[j], b[j + 1], j < 2 * k2 - 2 ? " " : "");
            j += 2;
        }
    }
    system("pause");
    return 0;
}
//Shortest Distance
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i, j, temp, x, sum = 0;
    scanf("%d", &n);
    int a[n], c[n + 1];      //由于运行超时利用数组存放距离计算
    c[0] = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        c[i + 1] = sum;
    }
    scanf("%d", &m);
    int b[m][2];
    for (i = 0; i < m; i++) {
        scanf("%d %d", &b[i][0], &b[i][1]);
        x = 0;
        if (b[i][0] > b[i][1]) {
            temp = b[i][0];
            b[i][0] = b[i][1];
            b[i][1] = temp;
        }
        x = c[b[i][1] - 1] - c[b[i][0] - 1];
        if (x > sum / 2) {
            printf("%d\n", sum - x);
        } else {
            printf("%d\n", x);
        }
    }
    system("pause");
    return 0;
}
//Colors in Mars
#include <stdio.h>
#include <stdlib.h>

char *decimal(int x);

int main() {
    int a[3], i;
    for (i = 0; i < 3; i++) {
        scanf("%d", &a[i]);
    }
    printf("#");
    for (i = 0; i < 3; i++) {
        printf("%s", decimal(a[i]));
    }
    system("pause");
    return 0;
}

char *decimal(int x) {     //13进制转换
    int m, n, c;
    char *p, str[3], color[4] = {'A', 'B', 'C'};
    p = str;
    m = x / 13;
    n = x % 13;
    if (m < 10) {
        str[0] = (char) (m + '0');
        if (n < 10) {
            str[1] = (char) (n + '0');
        } else {
            c = n - 10;
            str[1] = color[c];
        }
    } else {
        c = m - 10;
        str[0] = color[c];
        if (n < 10) {
            str[1] = (char) (n + '0');
        } else {
            c = n - 10;
            str[1] = color[c];
        }
    }
    return p;
}
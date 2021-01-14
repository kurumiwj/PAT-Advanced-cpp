//Have Fun with Numbers
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 1, n = 0, j = 0, x = 0;
    char a[25] = {'0'};
    int b[10] = {0}, c[25] = {0};
    while ((a[i] = getchar()) != '\n') {        //以输入换行符结束
        i++;
        n++;
    }
    for (i = 0; i <= 9; i++) {      //统计0-9每个数字出现了多少次
        for (j = 1; j <= n; j++) {
            if (a[j] - '0' == i) {
                b[i]++;
            }
        }
    }
    for (i = n; i >= 1; i--) {      //将输入的数据翻倍保存在一个整型数组中
        if (a[i] - '0' >= 5) {
            x = 2 * (a[i] - '0') - 10;
            c[i] = c[i] + x;
            c[i - 1]++;
        } else {
            x = 2 * (a[i] - '0');
            c[i] = c[i] + x;
        }
    }
    if (c[0] > 0) {     //如果翻倍后多了一位则为NO
        printf("No\n");
        for (i = 0; i <= n; i++) {
            printf("%d", c[i]);
        }
    } else {
        for (i = 0; i <= 9; i++) {
            x = 0;
            for (j = 1; j <= n; j++) {
                if (c[j] == i) {
                    x++;
                }
            }
            if (x != b[i]) {
                printf("No\n");
                for (i = 1; i <= n; i++) {
                    printf("%d", c[i]);
                }
                break;
            }
        }
        if (i == 10) {      //判断上轮循环是否执行完，如果全部完成则为YES，否则为NO
            printf("Yes\n");
            for (i = 1; i <= n; i++) {
                printf("%d", c[i]);
            }
        }
    }
    system("pause");
    return 0;
}
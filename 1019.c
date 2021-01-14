//General Palindromic Number
#include <stdio.h>
#include <stdlib.h>

//本题首先需要考虑输入为0的情况，其次需要考虑转换进制后的长度，不能简单定义整型，需要数组存放
typedef enum {
    false, true
} bool;

bool Palindromic(int a[], int n);

int main() {
    int n, b, a[50], i, count = 0;
    scanf("%d %d", &n, &b);
    if (n == 0) {       //先考虑n为0的情况，无论什么进制都是回文
        printf("Yes\n0\n");
    } else {
        for (i = 0; n > 0; i++) {
            a[i] = n % b;
            n /= b;
            count++;
        }
        if (Palindromic(a, count) == true)printf("Yes\n");
        else printf("No\n");
        for (i = i - 1; i >= 0; i--) {
            printf("%d%s", a[i], i > 0 ? " " : "\n");
        }
    }
    system("pause");
    return 0;
}

bool Palindromic(int a[], int n) {       //判断是否是回文
    int i;
    for (i = 0; i <= (n - 1) / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            break;
        }
    }
    if (i > (n - 1) / 2)return true;
    else return false;
}
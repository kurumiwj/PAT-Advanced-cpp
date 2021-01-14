//Be Unique
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, j, flag;
    int a[100000] = {0}, b[100000] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    for (i = 0; i < n; i++) {
        if (b[a[i]] == 1) {
            printf("%d", a[i]);
            return 0;
        }
    }
    printf("None");
    system("pause");
    return 0;
}
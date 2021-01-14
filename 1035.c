//Password
#include <stdio.h>
#include <stdlib.h>

typedef struct Account {
    char user[15];
    char password[15];
} acc;

int main() {
    int n, i, j, flag = 0, count = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        a[i] = 0;
    }
    acc account[n];
    for (i = 0; i < n; i++) {
        scanf("%s%s", account[i].user, account[i].password);
    }
    for (i = 0; i < n; i++) {
        flag = 0;
        for (j = 0; account[i].password[j] != '\0'; j++) {
            if (account[i].password[j] == '1') {
                account[i].password[j] = '@';
                flag = 1;
            }
            if (account[i].password[j] == '0') {
                account[i].password[j] = '%';
                flag = 1;
            }
            if (account[i].password[j] == 'l') {
                account[i].password[j] = 'L';
                flag = 1;
            }
            if (account[i].password[j] == 'O') {
                account[i].password[j] = 'o';
                flag = 1;
            }
        }
        if (flag == 1) {
            a[i]++;
        }
    }
    for (i = 0; i < n; i++) {
        if (a[i] > 0) {
            count++;
        }
    }
    if (n == 1 && count == 0) {
        printf("There is 1 account and no account is modified\n");
    } else if (n > 1 && count == 0) {
        printf("There are %d accounts and no account is modified\n", n);
    } else {
        printf("%d\n", count);
        for (i = 0; i < n; i++) {
            if (a[i] > 0) {
                printf("%s %s\n", account[i].user, account[i].password);
            }
        }
    }
    system("pause");
    return 0;
}
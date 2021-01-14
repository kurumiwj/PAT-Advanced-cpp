//Hello World for U
#include <stdio.h>
#include <stdlib.h>

int main() {
    char a[100], *p, *q;
    int i = 0, j, n1, n2, n3, count;
    while ((a[i] = getchar()) != '\n') {
        i++;
    }
    a[i] = '\0';
    count = i - 1;
    p = a;
    q = &a[count];
    n1 = count / 3 + 1;
    n3 = n1;
    n2 = count - n1 - n3;
    for (j = 0; j < n1 - 1; j++) {
        printf("%c", *(p + j));
        for (i = 0; i <= n2; i++) {
            printf(" ");
        }
        printf("%c\n", *(q - j));
    }
    p = &a[n1 - 1];
    q = &a[count + 1 - n3];
    for (j = 0; j < n2+3; j++) {
        printf("%c", *(p + j));
    }
    system("pause");
    return 0;
}
//Elevator
#include <stdio.h>
#include <stdlib.h>

int main() {
    const int UP = 6, DOWN = 4, STAY = 5;       //电梯上楼6秒，下楼4秒，停住不动5秒
    int n, i, t;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    t = a[0] * UP + STAY;
    for (i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            t = t + (a[i] - a[i - 1]) * 6 + STAY;
        } else if (a[i] < a[i - 1]) {
            t = t + (a[i - 1] - a[i]) * 4 + STAY;
        } else {
            t = t + STAY;
        }
    }
    printf("%d\n", t);
    system("pause");
    return 0;
}
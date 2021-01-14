//Emergency
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, c1, c2, i, j;      //n-城市的数量,m-路的数量,c1-目前所在的城市,c2-需要救援的城市
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    int a[n];       //每个城市救援队的数量
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int b[m][3];
    for (i = 0; i < m; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    system("pause");
    return 0;
}
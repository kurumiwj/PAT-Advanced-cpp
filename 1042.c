//Shuffling Machine
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char s[][5], int a[], int n);

int main() {
    int n, i;
    scanf("%d", &n);
    int a[54];
    for (i = 0; i < 54; i++) {
        scanf("%d", &a[i]);
    }
    char card[54][5] = {
            "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
            "H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
            "C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
            "D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
            "J1", "J2"
    };
    swap(card, a, n);
    return 0;
}

void swap(char s[][5], int a[], int n) {
    char card[54][5];
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < 54; i++) {
            for (j = 0; j < 54; j++) {
                if (a[j] == i + 1) {
                    strcpy(card[i], s[j]);
                    break;
                }
            }
        }
        for (i = 0; i < 54; i++) {
            strcpy(s[i], card[i]);
        }
    }
    for (i = 0; i < 54; i++) {
        printf("%s%s", card[i], i < 53 ? " " : "");
    }
}
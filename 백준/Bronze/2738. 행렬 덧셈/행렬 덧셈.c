#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[200][100] = { 0 }, b = 0, c = 0;
    scanf("%d %d", &b, &c);
    
    for (int i = 0; i < b; i++) {
        for (int t = 0; t < c; t++) {
            scanf("%d", &a[i][t]);
        }
    }

    for (int i = 0; i < b; i++) {
        for (int t = 0; t < c; t++) {
            scanf("%d", &a[100 + i][t]);
        }
    }

    for (int i = 0; i < b; i++) {
        for (int t = 0; t < c; t++) {
            printf("%d ", a[i][t] + a[100 + i][t]);
        }
        printf("\n");
    }
    return 0;
}
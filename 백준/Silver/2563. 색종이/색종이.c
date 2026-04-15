#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[100][100] = { 0 }, b = 0, c = 0, d = 0, ans = 0;
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
        scanf("%d %d", &c, &d);
        for (int t = 0;  t < 10; t++) {
            for (int k = 0; k < 10; k++) {
                a[c + t][d + k] = 1;
                }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int t = 0; t < 100;t++)
        {
            ans += a[i][t];
        }
    }
    printf("%d", ans);
    return 0;
}
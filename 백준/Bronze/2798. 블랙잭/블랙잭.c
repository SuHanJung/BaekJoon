#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[100] = { 0 }, n = 0, m = 0, answer = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == EOF) break;
    }
    for (int k = 0, p = 0; p < n - 2; p++) {
        for (int q = p + 1; q < n - 1; q++) {
            for (int r = q + 1; r < n; r++) {
                k = a[p] + a[q] + a[r];
                if (k <= m) {
                    if (k > answer) answer = k;
                }
                if (answer == m) {
                    printf("%d", answer);
                    return 0;
                }
            }
        }
    }
    printf("%d", answer);
    return 0;
}
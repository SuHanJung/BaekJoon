#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c[4] = { 0 };
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &b);
        c[0] = b / 25;
        b = b - 25 * c[0];
        c[1] = b / 10;
        b = b - 10 * c[1];
        c[2] = b / 5;
        b = b - 5 * c[2];
        c[3] = b;
        printf("%d %d %d %d\n", c[0], c[1], c[2], c[3]);
    }
    return 0;
}
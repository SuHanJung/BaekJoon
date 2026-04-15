#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    scanf("%d %d %d", &a, &b, &c);
    c -= a;
    d = a - b;
    if (c % d == 0) {
        printf("%d", c / d + 1);
    }
    else printf("%d", c / d + 2);
    return 0;
}
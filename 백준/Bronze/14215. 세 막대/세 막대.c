#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c, m;
    scanf("%d %d %d", &a, &b, &c);
    m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    if (2 * m >= a + b + c) printf("%d", 2 * (a + b + c - m) - 1);
    else printf("%d", a + b + c);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[2] = { 0 }, n = 0, c = 0;
    scanf("%d %d\n%d\n%d", &a[1], &a[0], &c, &n);
    if ((a[1] * n + a[0] <= n * c) && (a[1] <= c)) printf("1");
    else printf("0");
    return 0;
}
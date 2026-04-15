#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[6] = { 0 };
    scanf( "%d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5] );
    printf("%d %d %d %d %d %d", 1 - a[0], 1 - a[1], 2 - a[2], 2 - a[3], 2 - a[4], 8 - a[5]);
    return 0;
}
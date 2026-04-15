#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d", &a);
    for (; b < a; b++) {
        a -= b;
    }
    if (b % 2 == 1) {
        printf("%d\/%d", b - a + 1, a);
    }
    else {
        printf("%d\/%d", a, b - a + 1);
    }
    return 0;
}
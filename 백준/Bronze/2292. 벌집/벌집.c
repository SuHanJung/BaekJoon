#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 1, i = 0;
    scanf("%d", &a);
    if (a == 1) {
        printf("1");
        return 0;
    }

    for (; b < a; i++) {
        b = b + i * 6;
    }
    printf("%d", i);
    return 0;
}
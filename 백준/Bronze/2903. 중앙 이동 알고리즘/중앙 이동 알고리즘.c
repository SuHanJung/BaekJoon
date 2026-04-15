#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 2;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        b = b * 2 - 1;
    }
    printf("%d", b * b);
    return 0;
}
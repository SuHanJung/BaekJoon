#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long int a = 0, b = 0, d = 0;
    char c[50] = {0};
    scanf("%s %d", &c, &a);

    for (int i = 0; c[i] != 0; i++) {
        if (c[i] < 60) {
            b = c[i] - '0';
        }
        else {
            b = c[i] - 'A' + 10;
        }
        d = d * a + b;
    }

    printf("%d", d);
    return 0;
}
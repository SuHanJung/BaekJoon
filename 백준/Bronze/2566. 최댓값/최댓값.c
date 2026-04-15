#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 1, c = 1, d = 0;

    for (int i = 0; i < 9; i++) {
        for (int t = 0; t < 9; t++) {
            scanf("%d", &a);
            if (a > d) {
                d = a;
                b = i + 1;
                c = t + 1;
            }
        }
    }

    printf("%d\n%d %d", d, b, c);

    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 1, b = 1;
    for (;;) {
        scanf("%d %d", &a, &b);
        if ((a == 0) && (b == 0)) break;
        if (a % b == 0) printf("multiple");
        else {
            if (b % a == 0) printf("factor");
            else printf("neither");
        }
        printf("\n");
    }
    return 0;
}
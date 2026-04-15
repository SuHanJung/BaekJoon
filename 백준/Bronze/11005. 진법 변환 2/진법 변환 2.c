#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    char l[31] = { 0 };
    scanf("%d %d", &a, &b);

    if (a == 0) {
        printf("0");
        return 0;
    }

    for (int i = 0; a != 0; i++) {
        c = a % b;
        a /= b;

        if (c < 10) {
            l[30 - i] = c + '0';
        }
        else
        {
            l[30 - i] = c + 'A' - 10;
        }
    }

    for (int i = 0; i < 31; i++) {
        if(l[i] != 0) {
            printf("%c", l[i]);
        }
    }

    return 0;
}
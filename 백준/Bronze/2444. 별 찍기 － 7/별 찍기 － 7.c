#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0;
    char w[200] = { 0 };
    scanf("%d", &a);
    b = a + a - 1;
    for (int i = 0; i < a ; i++) {
        
        for (int k = 0; k <= b + 1; k++) {
            w[k] = ' ';
        }
        for (int t = a - i; t <= a + i;t++) {
            w[t] = '*';
        }
        for (int k = 1; k <= a + i; k++) {
            printf("%c", w[k]);
        }
        printf("\n");

    }
    for (int i = a - 2; i >= 0; i--) {

        for (int k = 0; k < b + 1; k++) {
            w[k] = ' ';
        }
        for (int t = a - i; t <= a + i; t++) {
            w[t] = '*';
        }
        for (int k = 1; k <= a + i; k++) {
            printf("%c", w[k]);
        }
        printf("\n");

    }

    return 0;
}
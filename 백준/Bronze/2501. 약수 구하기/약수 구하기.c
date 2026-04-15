#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d %d", &a, &b);
    for (int i = 1; b > 0;i ++) {
        if (a % i == 0) {
            b--;
            c = i;
        }
        if (i > a) { 
            printf("0"); 
            return 0; 
        }
    }
    printf("%d", c);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a, b, c;
    for (;;) {
        scanf("%d\n%d\n%d", &a, &b, &c);
        if ((a == 0) && (b == 0) && (c == 0)) break;
        if ((a + b <= c) || (b + c <= a) || (c + a <= b)) printf("Invalid");
        else {
            if ((a == b) && (b == c)) printf("Equilateral");
            else {
                if ((a != b) && (b != c) && (c != a)) {
                    printf("Scalene");
                }
                else printf("Isosceles");
            }
        }
        printf("\n");
    }
    return 0;
}
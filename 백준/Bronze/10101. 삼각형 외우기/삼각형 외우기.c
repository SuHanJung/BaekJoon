#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d\n%d\n%d", &a, &b, &c);
    if (a + b + c != 180) printf("Error");
    else {
        if ((a == 60) && (b == 60) && (c == 60)) printf("Equilateral");
        else {
            if ((a != b) && (b != c) && (c != a)) {
                printf("Scalene");
            }
            else printf("Isosceles");
        }
    }
    return 0;
}
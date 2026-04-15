#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long int a = 0;
    scanf("%d", &a);
    a = a * a - a;
    a /= 2;
    printf("%lld\n2", a);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long int a = 0;
    scanf("%d", &a);
    if (a == 0) {
        printf("1\n2");
        return 0;
    }
    printf("%lld\n2", a * a);
    return 0;
}
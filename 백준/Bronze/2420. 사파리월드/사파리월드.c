#include <stdio.h>
int main() {
    long long int a =0, b = 0;
    scanf("%lld %lld", &a, &b);
    if (a > b) printf("%lld", a - b);
    else printf("%lld", b - a);
    return 0;
}
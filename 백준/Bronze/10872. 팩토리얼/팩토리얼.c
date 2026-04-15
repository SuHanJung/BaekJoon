#include <stdio.h>
int main() {
    int a = 0, b = 1;
    for (scanf("%d", &a); a > 1;a--) b *= a;
    printf("%d",b);
    return 0;
}
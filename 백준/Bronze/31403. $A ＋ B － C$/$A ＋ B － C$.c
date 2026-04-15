#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", a + b - c);
    for(int t = 1;t <= b;t *= 10, a *= 10);
    printf("%d", a + b - c);
    return 0;
}
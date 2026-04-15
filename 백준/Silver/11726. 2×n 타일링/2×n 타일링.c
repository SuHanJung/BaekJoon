#include <stdio.h>
int main(){
    long long int a[1000] = {0}, input = 0;
    scanf("%lld", &input);
    a[1] = 1;
    a[2] = 2;
    for(int t = 3;t <= input;t++) a[t] = (a[t - 1] + a[t - 2]) % 10007;
    printf("%lld", a[input]);
    return 0;
}
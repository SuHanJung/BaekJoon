#include <stdio.h>
int main(){
    int n = 0, a = 0, b = 0;
    scanf("%d", &n);
    for(int t = 0;t < n;t++){
        scanf("%d,%d", &a, &b);
        printf("%d\n", a + b);
    }
    return 0;
}
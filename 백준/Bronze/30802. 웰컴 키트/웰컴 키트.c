#include <stdio.h>
int main(){
    int N, T, P, arr[6], ans = 0;
    scanf("%d%d%d%d%d%d%d%d%d", &N, &arr[0], &arr[1], &arr[2], &arr[3], &arr[4], &arr[5], &T, &P);
    for(int t = 0;t <= 5;t++) {
        ans += arr[t] / T;
        if(arr[t] % T != 0) ans++;
    }
    printf("%d\n", ans);
    printf("%d %d", N / P, N % P);
    return 0;
}
#include <stdio.h>

int main() {
    int n = 0, k = 0, arr[11] = {0}, inst = 0;
    scanf("%d %d", &n, &k);
    for(int t = 0;t < n;t++)scanf("%d", &arr[t]);
    for(int t = n - 1;t >= 0;t--){
    inst = k / arr[t];
    k -= inst * arr[t];
    arr[t] = inst;
    if (k == 0){
        for(int tt = 0;tt <= t;tt++) arr[tt] = 0;
        break;
    }
    }
    for(int t = 0;t < n;t++) inst += arr[t];
    printf("%d", inst);
    return 0;
}
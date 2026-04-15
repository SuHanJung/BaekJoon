#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0, K = 0, arr[100000][2] = { 0 }, ans[100001] = { 0 }, aa = 0, n = 0, nt = 0;
    scanf("%d %d", &N, &K);
    if (N >= K) {
        printf("%d", N - K);
        return 0;
    }
    if (N == 0) {
        N++;
        aa++;
    }
    arr[0][0] = N;
    ans[N] = 1;
    n = 1;
    for (; ans[K] == 0;) {
        for (int tt = 0; tt < n; tt++) {
            if (ans[arr[tt][0] - 1] == 0) {
                if (arr[tt][0] > 0) {
                    arr[nt][1] = arr[tt][0] - 1;
                    ans[arr[tt][0] - 1] = ans[arr[tt][0]] + 1;
                    nt++;
                }
            }
            if (ans[arr[tt][0] + 1] == 0) {
                arr[nt][1] = arr[tt][0] + 1;
                ans[arr[tt][0] + 1] = ans[arr[tt][0]] + 1;
                nt++;
            }
            if (arr[tt][0] <= 50000 && ans[arr[tt][0] * 2] == 0){
                arr[nt][1] = arr[tt][0] * 2;
                ans[arr[tt][0] * 2] = ans[arr[tt][0]] + 1;
                nt++;
            }
        }
        for (int t = 0; t < nt; t++) arr[t][0] = arr[t][1];
        n = nt;
        nt = 0;
    }
    printf("%d", ans[K] + aa - 1);
    return 0;
}
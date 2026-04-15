#include <stdio.h>
int main() {
int arr[1001] = {0}, N = 0;
    scanf("%d", &N);
arr[1] = 1;
arr[2] = 3;
    for(int t = 3;t <= N;t++) arr[t] = (arr[t - 1] + 2 * arr[t - 2]) % 10007;
    printf("%d", arr[N]);
return 0;
}
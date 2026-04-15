#include <stdio.h>

int main() {
    int T, N, fibonacci[41][2] = {0};
    fibonacci[0][0] = 1;
    fibonacci[1][1] = 1;
    for(int t = 2;t <= 40;t++){
        fibonacci[t][0] = fibonacci[t - 1][0] + fibonacci[t - 2][0];
        fibonacci[t][1] = fibonacci[t - 1][1] + fibonacci[t - 2][1];
    }
    scanf("%d", &T);
    for(int t = 1; t <= T;t++){
        scanf("%d", &N);
        printf("%d %d\n", fibonacci[N][0], fibonacci[N][1]);
    }
    return 0;
}
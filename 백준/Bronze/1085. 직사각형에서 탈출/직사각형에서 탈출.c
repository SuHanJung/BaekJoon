#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int in[4] = { 0 };
    scanf("%d %d %d %d", &in[0], &in[1], &in[2], &in[3]);
    in[2] -= in[0];
    in[3] -= in[1];
    for (int ans = in[0], i = 0; i < 4; i++) {
        if (in[i] < ans) ans = in[i];
        if (i == 3) printf("%d", ans);
    }
    return 0;
}
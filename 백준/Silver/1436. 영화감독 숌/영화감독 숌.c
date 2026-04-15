#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int disnum(int n) {
    for (int t = n; t > 100; t /= 10) {
        if (t % 1000 == 666) return 1;
    }
    return 0;
}

int main() {
    int answer = 0, num = 666, count = 1, pur = 0;
    scanf("%d", &pur);
    for (; count <= pur; num++) {
        if (disnum(num) == 1) count++;
    }
    answer = num - 1;
    printf("%d", answer);
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int input[3] = { 0 }, num[10001] = { 0 }, answer = 0, max = 0;
    scanf("%d %d", &input[1], &input[2]);
    for (int count = 0; count < input[1]; count++) {
        scanf("%d", &input[0]);
        num[input[0]]++;
        if (input[0] > max) max = input[0];
    }
    for (int count = max + 1;; count--) {
        if (num[count] >= input[2]) {
            answer = count;
            break;
        }
        else input[2] -= num[count];
    }
    printf("%d", answer);
    return 0;
}
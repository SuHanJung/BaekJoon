#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int input[5] = { 0 }, num[10] = { 0 }, answer[2] = { 0 };
    for (int count = 0; count < 5; count++) {
        scanf("%d", &input[count]);
        answer[0] += input[count];
        num[input[count] / 10]++;
    }
    answer[0] /= 5;
    for (int ch = 0,count = 0; count < 10;count++) {
        ch += num[count];
        if (ch >= 3) {
            answer[1] = count * 10;
            break;
        }
    }
    printf("%d\n%d", answer[0], answer[1]);
    return 0;
}
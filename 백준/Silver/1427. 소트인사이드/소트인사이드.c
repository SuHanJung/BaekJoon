#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long int input = 0;
    int answer[10] = { 0 };
    scanf("%d", &input);
    for (int digit = 0;input != 0;) {
        digit = input % 10;
        input /= 10;
        answer[digit]++;
    }
    for (int digit = 9; digit >= 0; digit--) {
        for (int count = answer[digit]; count > 0; count--) printf("%d", digit);
    }

    return 0;
}
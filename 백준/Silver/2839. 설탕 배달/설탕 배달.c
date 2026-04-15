#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int answer = 0, num = 0, five = 0, three = 0;
    scanf("%d", &num);
        for (; num >= 5;) {
            num -= 5;
            five++;
        }
        for (; num >= 3;) {
            num -= 3;
            three++;
        }
        for (; num != 0;) {
            if (five > 0) {
                five--;
                num += 5;
            }
            else {
                printf("-1");
                return 0;
            }
            for (; num >= 3;) {
                num -= 3;
                three++;
            }
        }
        answer = five + three;
        printf("%d", answer);
    return 0;
}
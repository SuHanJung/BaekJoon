#include <stdio.h>
int main() {
    int input = 0, a[7] = {0}, ans = 0;
    scanf("%d", &input);
    for(int num = input - 54; num < input; num++) {
        for(int inst = num, count = 0;count < 7;count++) {
            a[count] = inst % 10;
            inst /= 10;
        }
        ans = num;
        for(int count = 0;count < 7;count++) {
            ans = ans + a[count];
        }
        if(ans == input) {
            printf("%d", num);
            return 0;
        }
    }
    printf("0");
    return 0;
}
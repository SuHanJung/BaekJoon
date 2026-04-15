#include <stdio.h>
int main() {
    char a[2] = { 0 };
    int score = 0, flo = 0;
    scanf("%s",a);
    if (a[0] == 'F') {
        printf("0.0");
        return 0;
    }
    score = 69 - a[0];
    if (a[1] == '-') {
        flo = 7;
        score--;
        }
    if (a[1] == '+') flo = 3;
    printf("%d.%d", score, flo);
    return 0;
}
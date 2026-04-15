#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int input = 0,instvar = 0, answer[2001] = { 0 };
    scanf("%d", &input);
    for (int count = 0; count < input; count++) {
        scanf("%d", &instvar);
        answer[instvar + 1000]++;
    }
    for (int count = 0;count <= 2000;count++) {
        if (answer[count] == 1) {
            printf("%d\n", count - 1000);
        }
    }
    return 0;
}
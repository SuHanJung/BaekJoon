#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b[26] = { 0 };
    char p[101] = { 0 }, q = 'a';
    scanf("%s", &p);
    for (int i = 0, k = 0; p[i] != 0; i++) {
        k = p[i] - q;
        if (b[k] == 0) {
            b[k] = i + 1;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", b[i] - 1);
    }
    return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[26] = { 0 }, b = 0, t = 0;
    char w[101] = { 0 };
    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        scanf("%s", &w);
        for (int i = 0; w[i] != 0; i++) {
            if (w[i] != w[i + 1]) a[w[i] - 'a']++;
            w[i] == 0;
        }
        for (int i = 0, ch = 0; i < 26; i++) {
            if ((a[i] > 1)) ch++;
            a[i] = 0;
            if ((i == 25) && (ch == 0)) b++;
        }
    }
    printf("%d", b);
    return 0;
}
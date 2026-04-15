#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[26] = { 0 }, b = 0;
    char w[1000001] = { 0 }, ans = 0;
    scanf("%s", &w );
    
    for (int i = 0; w[i] != 0; i++) {
        if (w[i] < 95) {
            a[w[i] - 'A']++;
        }
        else {
            a[w[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {

        if (a[i] > b) {
            b = a[i];
            ans = i + 'A';
        }
        else {
            if (a[i] == b) ans = '?';
        }
    }

    printf("%c", ans);
    return 0;
}
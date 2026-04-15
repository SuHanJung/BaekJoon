#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int ans = 0, c = 0, b = 0, a[11] = {0, 0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
    char str[17] = { 0 };
    scanf("%s", &str);
    for (int i = 0; str[i] != 0; i++) {
        for (int t = 0, k = str[i] - 64; k > 0; t++) {
            k -= a[t];
            c = t;
        }
        ans += c;
    }

    printf("%d", ans);
    return 0;
}
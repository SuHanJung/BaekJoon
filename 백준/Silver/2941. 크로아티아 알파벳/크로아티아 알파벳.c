#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0;
    char w[101] = { 0 };
    scanf("%s", &w );
    for (; w[b] != 0; b++) {
        if ((w[b] == 'j') && ((w[b - 1] == 'l') || (w[b - 1] == 'n'))) a++;

        if ((w[b] == '=') && ((w[b - 1] == 'z') || (w[b - 1] == 's') || (w[b - 1] == 'c'))) {
            a++;
            if ((w[b - 1] == 'z') && (w[b - 2] == 'd')) a++;
        }
            
        if (w[b] == '-') a++;

    }

    printf("%d", b - a);
    return 0;
}
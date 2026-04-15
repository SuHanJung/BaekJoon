#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
    char p[1000003] = { 0 };
    gets(p);
    
    if ((p[1] == 0) && (p[0] == ' ')) {
        printf("0");
        return 0;
    }
    else;

    if (p[2] == 0) {
        printf("1");
        return 0;
    }
    else;
    
    for (int t = 1; p[t + 1] != 0; t++) {
        if (p[t] == ' ') a++;
    }
    
    printf("%d", a + 1);
    return 0;
}
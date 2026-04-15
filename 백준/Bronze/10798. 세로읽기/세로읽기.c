#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0;
    char ex[16] = { 0 }, ans[76] = { 0 };
    
    for (int i = 0; i < 5; i++) {
        scanf("%s", &ex);
        for (int t = 0; ex[t] != 0; t++) {
                ans[t * 5 + i] = ex[t];
        }
    }

    for (int i = 0; i < 76; i++) {
        if(ans[i] != 0) printf("%c", ans[i]);
    }
    return 0;
}
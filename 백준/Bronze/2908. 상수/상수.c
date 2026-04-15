#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0;
    scanf("%d %d", &a, &b); 
    if (a % 10 == b % 10) {
        if ((a / 10) % 10 == (b / 10) % 10) {
            if (a > b) c = 1;
            else c = 2;
        }
        else {
            if ((a / 10) % 10 > (b / 10) % 10) c = 1;
            else c = 2;
        }
        }
        else { 
            if (a % 10 > b % 10) c = 1;
            else c = 2;
        }

        if (c == 1) {
            printf("%d%d%d", a % 10, (a / 10) % 10, a / 100 );
        }
        
        if(c == 2){
            printf("%d%d%d", b % 10, (b / 10) % 10, b / 100);
        }
    
    return 0;
}
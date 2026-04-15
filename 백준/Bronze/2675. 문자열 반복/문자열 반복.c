#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0;
    char p[21] = { 0 };
    scanf("%d", &a);
    
    for (int t = 0; t < a; t++) {
        
        scanf("%d", &b);
        scanf("%s", &p);
        
        for (int i = 0; p[i] != 0; i++) {
            
            for (int k = 0; k < b; k++) {
                printf("%c", p[i]);
            }
            p[i] = 0;

        }
        printf("\n");

    }
 
    return 0;
}
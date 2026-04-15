#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, to = 0;
    float score = 0, total = 0, b = 0;
    char w[60] = { 0 };
    for (int i = 0; i < 20; i++) {
        gets(&w);
        for (int t = 0; (w[t] != 0) || (w[t + 1] != 0); t++) {
            if (w[t] == ' ') {
                if (w[t + 1] < 58) { 
                    a = w[t + 1] - '0';
                    to += a;
                }
                else {
                    b = 'A' + 4 - w[t + 1];
                    
                    if (w[t + 2] == '+') b += 0.5;
                    if (b < -1) to -= a;
                    if (b < 0) b = 0;   
                
                    total += a * b;
                }
            
            }

        }
        for (int t = 0; t < 59; t++) {
            w[t] = 0;
        }
    }

    printf("%f", total / to);

    return 0;
}
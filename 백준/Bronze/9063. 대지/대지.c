#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a = 0, b = 0, t = 0, min[2] = { 0 }, max[2] = { 0 };
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        if (i == 0) {
            min[0] = a;
            max[0] = a;
            min[1] = b;
            max[1] = b;
        }
        if (min[0] > a) min[0] = a;
        if (min[1] > b) min[1] = b;
        if (max[0] < a) max[0] = a;
        if (max[1] < b) max[1] = b;
    }
    printf("%d", (max[0] - min[0]) * (max[1] - min[1]));
    return 0;
}
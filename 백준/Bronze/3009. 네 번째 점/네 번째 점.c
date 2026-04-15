#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x[3] = { 0 }, y[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    if (x[0] == x[1]) printf("%d ", x[2]);
    if (x[2] == x[1]) printf("%d ", x[0]);
    if (x[2] == x[0]) printf("%d ", x[1]);
    if (y[0] == y[1]) printf("%d", y[2]);
    if (y[2] == y[1]) printf("%d", y[0]);
    if (y[2] == y[0]) printf("%d", y[1]);
    return 0;
}
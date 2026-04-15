#include <stdio.h>
int main() {
    int a = 0, b = 1;
    scanf("%d", &a);
    for (int time = 1; time <= a;time++){
        b *= time;
    }
    printf("%d",b);
    return 0;
}
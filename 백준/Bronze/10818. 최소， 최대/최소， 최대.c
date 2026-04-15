#include<stdio.h>
int main(){
    int N, Max = -1000000, Min = 1000000;
    scanf("%d", &N);
    for(int input;N > 0;N--, scanf("%d", &input), Max = (input > Max) ? input:Max, Min = (input < Min) ? input:Min);
    printf("%d %d", Min, Max);
    return 0;
}
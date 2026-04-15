#include <stdio.h>
int main(){
    int N, T = 1;
    scanf("%d", &N);
    for(int t = 1;T <= N;t++) {
        printf("*");
        if(t == T){
            T++;
            t = 0;
            printf("\n");
        }
    }
    return 0;
}
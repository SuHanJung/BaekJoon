#include<stdio.h>
int main(){
    int a;
    scanf("%d", &a);
    for(int b = a;a > 0;a--){
        for(int t = 0;t< b - a;t++) printf(" ");
        for(int t = 0;t<a;t++) printf("*");
        printf("\n");
    }
    return 0;
}
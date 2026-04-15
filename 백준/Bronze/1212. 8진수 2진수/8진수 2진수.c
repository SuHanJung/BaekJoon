#include<stdio.h>
int main(){
    char arr[3333344] = {0}, f[10] = { 0 };
    scanf("%s", arr);
    if(arr[0] == '0') {
        printf("0");
        return 0;
    }
    arr[0] -= '0';
    f[0] = arr[0] / 4;
    f[1] = (arr[0] % 4) / 2;
    f[2] = arr[0] % 2;
    for(int t = 0;t <= 2;t++){
        if(f[t] != f[9]){ 
            printf("%c", f[t] + '0');
            f[9] = 100;
        }
    }
    for(int t = 1;arr[t] != 0;t++){
        arr[t] -= '0';
        f[0] = arr[t] / 4;
        f[1] = (arr[t] % 4) / 2;
        f[2] = arr[t] % 2;
        for(int tt = 0; tt <= 2;tt++) printf("%c", f[tt] + '0');
    }
    
    
    return 0;
}
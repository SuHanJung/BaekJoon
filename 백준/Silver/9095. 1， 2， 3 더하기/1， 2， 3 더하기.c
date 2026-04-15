#include <stdio.h>
int main(){
    int ans[11] = {0, 1, 2, 4, 7, 13, 24, 44, 81, 149, 274}, n = 0;
    int input = 0;
    scanf("%d",&n);
    for(int t = 0; t < n;t++){
        scanf("%d", &input);
        printf("%d\n",ans[input]);
        }
    return 0;
}
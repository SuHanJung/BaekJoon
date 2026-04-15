#include <stdio.h>
int main(){
    int n = 0;
    char line[10] = {0};
    for(int tt = 0;n == 0;tt++){
    scanf("%s", line);
    if(line[0] < 60){
        for(int t = 0;line[t] != 0;t++){
            n = n * 10 + line[t] - '0';
        }
        n += 3 - tt;
    }
    }
    if(n % 15 == 0) printf("FizzBuzz");
    else if (n % 3 == 0) printf("Fizz");
    else if (n % 5 == 0) printf("Buzz");
    else printf("%d", n);
    return 0;
}
#include <stdio.h>
long long int fu(long long int n, long long int k) {
	
	if (n == 1) return 0;
	else if (n < k) return (fu(n - 1, k) + k) % n;
	long long int re = 0;
	re = fu(n - n / k, k) - (n % k);
	if (re < 0) re += n;
	else re = re + re / (k - 1);
	return re;
}

int main(){
	long long int N = 0, K = 0, ans = 0;
	scanf("%lld %lld", &N, &K);
    if(K == 1){
        printf("%lld", N);
        return 0;
    }
	ans = fu(N, K) + 1;
	printf("%lld", ans);
	return 0;
}
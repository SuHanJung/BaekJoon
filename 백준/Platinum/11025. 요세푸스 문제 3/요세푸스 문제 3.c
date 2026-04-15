#include <stdio.h>
int main(){
	int N = 0, K = 0, arr = 1;
	scanf("%d %d", &N, &K);
	for (int t = 2; t <= N; t++) {
		arr = (arr + K - 1) % t + 1;
	}
	printf("%d", arr);
	return 0;
}
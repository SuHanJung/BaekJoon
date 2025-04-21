#include <stdio.h>
int main() {
	long long int M = 0, K = 0, ways[23] = { 0 }, CY[110000] = { 0 }, cycle = 0, aarr[100000] = { 0 }, loop_start = 30;
	long long int ans = 0;
	scanf("%lld", &M);
	scanf("%lld", &K);
	for (int t = 0; t < K; t++) scanf("%lld", &ways[t]);
	for (int t = 0; t < K; t++) CY[ways[t]] = 1;
	for (int t = 1; t <= 100000; t++) {
		if (CY[t] == 0) {
			aarr[ans] = t;
			ans++;
			for (int n = 0; n < K; n++) CY[t + ways[n]] = 1;
            }
        if( t >= M ) {
            printf("%lld", ans);
            return 0;
    }
}
	ans = 0;
	for (; ans == 0; loop_start++) {
		for (cycle = 2;; cycle++) {
			for (int cycleTest = 1;; cycleTest++) {
				if (CY[cycle + cycleTest + aarr[loop_start]] != CY[cycleTest + aarr[loop_start]]) break;
				if (cycleTest >= 50000) {
					for(int ansInLoop = 0;aarr[loop_start + ansInLoop] < cycle + aarr[loop_start];ansInLoop++)
                    ans++;
                    break;
				}
			}
			if (ans != 0 || cycle > 6000) break;
		}
	}
	M -= aarr[loop_start] - 1;
	ans *= M / cycle;
	for (int t = 0; t < M % cycle; t++) {
		if(CY[aarr[loop_start] + t] == 0) ans++;
	}
    ans += loop_start;
	printf("%lld", ans);
	return 0;
}
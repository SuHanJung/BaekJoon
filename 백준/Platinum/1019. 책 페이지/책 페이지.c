#include <stdio.h>

int main() {
	int ans[10] = { 0 }, N = 0, Narr[11] = { 0 }, len = 0, llen = 0;
	scanf("%d", &N);
	for (int inst = N; inst > 0; len++, inst /= 10) Narr[len] = inst % 10;
	len--;
	llen = len;
	for (int inst = 0; len >= 0; len--) {
		if (len > 0) {
			inst = Narr[len] * len;
			for (int t = 1; t < len; t++) inst *= 10;
			for (int t = 0; t < 10; t++) ans[t] += inst;
			if (Narr[len] == 0) {
				inst = 1;
				for (int t = 0; t < len; t++) inst *= 10;
				ans[0] -= inst;
				//ans[0]++;
			}
		}
		inst = 1;
		for (int t = 0; t < len; t++) inst *= 10;
		for (int t = 1; t < Narr[len]; t++) ans[t] += inst;
		inst = 0;
		
		for (int t = len - 1; t >= 0; t--) {
			inst *= 10;
			inst += Narr[t];
		}
			ans[Narr[len]] += inst + 1;
			inst = 1;
		
	}
	if (N % 10 == 0) ans[0]--;
	for (int t = 0; t < 10; t++) printf("%d ", ans[t]);
	return 0;
}
#include <stdio.h>
#include <malloc.h>

int main() {
	int a, b, st[1000000][2] = { 0 };
	scanf("%d %d", &a, &b);
	st[0][0] = a;
	st[0][1] = 1;
	for (int t = 0, piv = 1; t < piv; t++) {
		if (st[t][0] <= 500000000) {
			st[piv][0] = st[t][0] * 2;
			if (st[piv][0] == b) {
				printf("%d", st[t][1] + 1);
				return 0;
			}
			st[piv++][1] = st[t][1] + 1;
			if (st[t][0] < 100000000) {
				st[piv][0] = st[t][0] * 10 + 1;
				if (st[piv][0] == b) {
					printf("%d", st[t][1] + 1);
					return 0;
				}
				st[piv++][1] = st[t][1] + 1;
			}
		}
	}
	printf("-1");
	return 0;
}
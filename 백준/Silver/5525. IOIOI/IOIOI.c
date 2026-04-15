#include <stdio.h>

int main() {
	int N = 0, M = 0, ans = 0;
	char st[1000002] = { 0 };
	scanf("%d\n%d", &N, &M);
	scanf("%s", st);
	for (int count = 0, t = 0; t < M; t++) {
		count = 0;
		if (st[t] == 'I') {
			t++;
			for (; st[t] == 'O' && st[t + 1] == 'I';) {
				t += 2;
				count++;
			}
			t--;
			count -= N - 1;
			if (count > 0) ans += count;
		}
	}
	printf("%d", ans);
	return 0;
}
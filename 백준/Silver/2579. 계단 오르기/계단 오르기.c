#include <stdio.h>

int main() {
	int N = 0, inarr[301] = { 0 }, ans[301][2] = { 0 };
	scanf("%d", &N);
	for (int t = 1; t <= N; t++) scanf("%d", &inarr[t]);
	ans[1][0] = inarr[1];
	ans[2][1] = inarr[2];
	ans[2][0] = ans[1][0] + inarr[2];
	for (int t = 3; t <= N; t++) {
		ans[t][0] = ans[t - 1][1] + inarr[t];
		if (ans[t - 2][0] > ans[t - 2][1]) ans[t][1] = inarr[t] + ans[t - 2][0];
		else ans[t][1] = inarr[t] + ans[t - 2][1];
	}
	if (ans[N][0] > ans[N][1]) printf("%d", ans[N][0]);
	else printf("%d", ans[N][1]);
	return 0;
}
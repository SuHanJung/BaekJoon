#include <stdio.h>

int same(char a[], char b[]) {
	for (int t = 0;a[t] != 0 || b[t] != 0; t++) {
		if (a[t] != b[t]) return 0;
	}
	return 1;
}

int main() {
	int T = 0, n = 0, cl[31] = { 0 }, ans = 1;
	char clname[31][21] = { 0 }, name[21] = { 0 }, cltype[21] = { 0 };
	scanf("%d", &T);
	for (; T > 0; T--) {
		scanf("%d", &n);
		for (int t = 0; t < n; t++) {
			scanf("%s %s", name, cltype);
			for (int tt = 0;; tt++) {
				if (cl[tt] == 0) {
					for (int i = 0; i < 20; i++)clname[tt][i] = cltype[i];
					cl[tt]++;
					break;
				}
				else if (same(cltype, clname[tt]) == 1) {
					cl[tt]++;
					break;
				}
			}
		}
		for (int t = 0; t < n; t++) {
			ans *= cl[t] + 1;
			cl[t] = 0;
			for (int tt = 0; tt < 21; tt++) clname[t][tt] = 0;
		}
		ans--;
		printf("%d\n", ans);
		ans = 1;
	}
	return 0;
}
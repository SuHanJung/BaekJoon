#include <stdio.h>
int main() {
	int n = 0, l[1001] = { 0 };
	l[2] = 1;
	l[4] = 1;
	for (int t = 1; t <= 1000; t++) {
		if (l[t] == 0) {
			l[t + 1] = 1;
			l[t + 3] = 1;
			l[t + 4] = 1;
		}
	}
	scanf("%d", &n);
	if (l[n] == 1) printf("SK");
	else printf("CY");
	return 0;
}
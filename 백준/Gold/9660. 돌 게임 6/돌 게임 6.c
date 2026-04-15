#include <stdio.h>
int main() {
	long long int n = 0;
    int l[14] = { 0 };
	scanf("%lld", &n);
    l[1] = 1;
    l[3] = 1;
	l[4] = 1;
	for (int t = 0; t <= 6; t++) {
		if (l[t] == 0) {
			l[t + 1] = 1;
			l[t + 3] = 1;
			l[t + 4] = 1;
		}
	}
	if (l[n % 7] == 1) printf("SK");
	else printf("CY");
	return 0;
}
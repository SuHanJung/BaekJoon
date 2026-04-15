int main() {
	unsigned long long int n, m, ansn = 0, ansm = 0;
	unsigned long long int bi[55] = { 1, 2 }, tot[55] = { 0, 1 };
	scanf("%llu%llu", &n, &m);
	n--;
	for (int t = 2; t < 55; t++) {
		bi[t] = bi[t - 1] * 2;
		tot[t] = tot[t - 1] * 2 + bi[t - 2];
	}
	for (int t; n > 0;) {
		for (t = 0; bi[t] <= n; t++) ansn += tot[t];
		t--;
		n -= bi[t];
		ansn += n + 1;
	}
	for (int t; m > 0;) {
		for (t = 0; bi[t] <= m; t++) ansm += tot[t];
		t--;
		m -= bi[t];
		ansm += m + 1;
	}
	printf("%llu",ansm - ansn);
	return 0;
}
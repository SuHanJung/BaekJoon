unsigned long long int re(unsigned long long int x) {
	unsigned long long int mod = 1000000007, ans = 1, y = mod - 2;
	while (y > 0) {
		if (y % 2 != 0) {
			ans *= x;
			ans %= mod;
		}
		x *= x;
		x %= mod;
		y /= 2;
	}
	return ans;
}


int main() {
	unsigned long long int M, ans = 0, mod = 1000000007;
	scanf("%llu", &M);
	for (unsigned long long int t = 0, N, S; t < M; t++) {
		scanf("%llu%llu", &N, &S);
		ans += (S * re(N)) % mod;
		ans %= mod;
	}
	printf("%llu", ans);
	return 0;
}
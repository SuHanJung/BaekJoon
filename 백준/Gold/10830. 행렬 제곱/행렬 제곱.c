void cal(unsigned long long int a[5][5], unsigned long long int b[5][5], unsigned long long int ans[5][5], unsigned long long int N) {
	for (int t = 0; t < N; t++) for (int tt = 0; tt < N; tt++) for (int ttt = 0; ttt < N; ttt++) { 
		ans[t][tt] += a[t][ttt] * b[ttt][tt];
		ans[t][tt] %= 1000;
	}
}

int main() {
	unsigned long long int N, B, arr[40][5][5] = { 0 }, n = 2;
	scanf("%llu%llu", &N, &B);
	for (int t = 0; t < N; t++) for (int tt = 0; tt < N; tt++) scanf("%llu", &arr[0][t][tt]);
	for (int t = 1; n <= B; t++, n *= 2) {
		cal(arr[t - 1], arr[t - 1], arr[t], N);
	}
	for (int t = 0; t < N; t++) arr[38][t][t] = 1;
	for (int t = 0; B > 0; B /= 2, t++) if (B % 2 == 1) {
        for (int tt = 0; tt < N; tt++) for (int ttt = 0; ttt < N; ttt++) arr[39][tt][ttt] = 0;
        cal(arr[t], arr[38], arr[39], N);
        for (int tt = 0; tt < N; tt++) for (int ttt = 0; ttt < N; ttt++) arr[38][tt][ttt] = arr[39][tt][ttt];
    }
	for (int t = 0; t < N; t++) {
		for (int tt = 0; tt < N; tt++) printf("%llu ", arr[39][t][tt]);
		printf("\n");
	}
	return 0;
}
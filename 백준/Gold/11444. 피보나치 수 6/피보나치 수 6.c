void execute(unsigned long long int *arr1, unsigned long long int *arr2) {
	unsigned long long int memory[3];
	memory[0] = arr1[1] * arr2[1] + arr1[0] * arr2[0];
	memory[1] = arr1[2] * arr2[1] + arr1[1] * arr2[0];
	memory[2] = arr1[2] * arr2[2] + arr1[1] * arr2[1];
	for(int t = 0;t< 3;t++) arr1[t] = memory[t] % 1000000007;
}

int main() {
	unsigned long long int arr[60][3] = { 0 }, N, ans[3] = { 1, 0, 1 };
	scanf("%llu", &N);
	arr[0][0] = 0;
	arr[0][1] = 1;
	arr[0][2] = 1;
	for (int t = 1; t < 60; t++) {
		for (int tt = 0; tt < 3; tt++) arr[t][tt] = arr[t - 1][tt];
		execute(arr[t], arr[t]);
	}
	for (unsigned long long int n = 0; N > 0; N /= 2, n++) {
		if (N % 2 == 1) execute(ans, arr[n]);
	}
	printf("%llu", ans[1]);
	return 0;
}
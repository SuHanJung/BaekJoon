int main() {
	int N, max = 0, arr[1000][3] = { 0 };
	scanf("%d", &N);
	for (int t = 0; t < N; t++) scanf("%d", &arr[t][0]);
	for (int t = 0; t < N; t++) for (int tt = 0; tt < t; tt++) if (arr[tt][0] < arr[t][0] && arr[tt][1] + 1 > arr[t][1]) arr[t][1] = arr[tt][1] + 1;
	for (int t = N - 1; t >= 0; t--) for (int tt = N - 1; tt > t; tt--) if (arr[tt][0] < arr[t][0] && arr[tt][2] + 1 > arr[t][2]) arr[t][2] = arr[tt][2] + 1;
	for (int t = 0; t < N; t++) if (max < arr[t][1] + arr[t][2]) max = arr[t][1] + arr[t][2];
	printf("%d", max + 1);
	return 0;
}
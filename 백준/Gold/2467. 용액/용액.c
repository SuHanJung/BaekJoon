#include <malloc.h>

int mtp(int k) {
	if (k < 0) return 0 - k;
	else return k;
}

int main(){
	int N, *arr, ans, ansl, ansr;
	scanf("%d", &N);
	arr = malloc(sizeof(int) * N);
	for (int t = 0; t < N; t++) scanf("%d", &arr[t]);
	if (arr[0] > 0) {
		printf("%d %d", arr[0], arr[1]);
		free(arr);
		return 0;
	}
	else if (arr[N - 1] < 0) {
		printf("%d %d", arr[N - 2], arr[N - 1]);
		free(arr);
		return 0;
	}
    ans = mtp(arr[0] + arr[N - 1]);
    ansl = arr[0];
    ansr =arr[N - 1];
	for (int l = 0, r = N - 1; l < r; ) {
		if (ans > mtp(arr[r] + arr[l])) {
			ans = mtp(arr[r] + arr[l]);
			ansl = arr[l];
			ansr = arr[r];
		}
		if (arr[l] + arr[r] < 0) l++;
		else r--;
	}
	printf("%d %d", ansl, ansr);
	free(arr);
	return 0;
}
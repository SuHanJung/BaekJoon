#include <stdio.h>
#include <stdlib.h>

int clean(unsigned long long int arr[], int len, int size) {
	unsigned long long int answer[1000000] = { 0 };
	int l = size / 2;
	for (int count = 0; size * (count + 1) <= len; count++) {
		for (int starta = size * count, startb = size * count + l, timea = 0, timeb = 0; timea + timeb < size;) {
			if (timea == l) {
				answer[starta + timea + timeb] = arr[startb + timeb];
				timeb++;
			}
			else {
				if (timeb == l) {
					answer[starta + timea + timeb] = arr[starta + timea];
					timea++;
				}
				else {
					if (arr[starta + timea] > arr[startb + timeb]) {
						answer[starta + timea + timeb] = arr[startb + timeb];
						timeb++;
					}
					else {
						answer[starta + timea + timeb] = arr[starta + timea];
						timea++;
					}
				}
			}
		}
	}
	if (len % size > l) {
		for (int starta = (len / size) * size, startb = (len / size) * size + l, timea = 0, timeb = 0; timea + timeb < len % size;) {
			if (timea == l) {
				answer[starta + timea + timeb] = arr[startb + timeb];
				timeb++;
			}
			else {
				if (timeb == len % l) {
					answer[starta + timea + timeb] = arr[starta + timea];
					timea++;
				}
				else {
					if (arr[starta + timea] > arr[startb + timeb]) {
						answer[starta + timea + timeb] = arr[startb + timeb];
						timeb++;
					}
					else {
						answer[starta + timea + timeb] = arr[starta + timea];
						timea++;
					}
				}
			}
		}
	}
	else {
		for (int count = (len / size) * size; count < len; count++) {
			answer[count] = arr[count];
		}
	}
	for (int k = 0; k < len; k++) {
		arr[k] = answer[k];
	}
	return 0;
}


int Jsort(unsigned long long int input[], int n) {
	for (int size = 1; n > size;) {
		size *= 2;
		clean(input, n, size);
	}
	return 0;
}

int main() {
	unsigned long long int N = 0, M = 0, tree[1000000] = { 0 }, tot = 0, ans = 0;
	scanf("%llu %llu", &N, &M);
	for (int t = 0; t < N; t++) {
		scanf("%llu", &tree[t]);
	}
	Jsort(tree, N);

	for (int t = 1; tot < M && t < N; t++) {
		tot += t * (tree[N - t] - tree[N - t - 1]);
		ans = N - t - 1;
	}
	if(ans == 0 && tot < M){
		ans = tree[ans] -= 1 + (M - tot - 1) / N;
	}
	else ans = tree[ans] + ((tot - M) / (N - ans - 1));
	printf("%llu", ans);
	return 0;
}
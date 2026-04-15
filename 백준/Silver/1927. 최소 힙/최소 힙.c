#include <stdio.h>
int main() {
	long long int N = 0, heap[100010] = { 0 }, input = 0, n = 0, inst = 0;
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf("%d", &input);
		if (input == 0) {
			if (n == 0) printf("0\n");
			else {
				printf("%d\n", heap[1]);
				heap[1] = heap[n];
                heap[n] = 0;
				n--;
				for (int t = 1, k = 0; t * 2 + 1 <= n;) {
					if (heap[2 * t] < heap[2 * t + 1]) {
						if (heap[2 * t] < heap[t]) {
							k = heap[2 * t];
							heap[2 * t] = heap[t];
							heap[t] = k;
							t = 2 * t;
						}
						else break;
					}
					else {
						if (heap[2 * t + 1] < heap[t]) {
							k = heap[2 * t + 1];
							heap[2 * t + 1] = heap[t];
							heap[t] = k;
							t = 2 * t + 1;
						}
						else break;	
					}
                }
					if (n % 2 == 0) {
						if (heap[n] < heap[n / 2]) {
							inst = heap[n];
							heap[n] = heap[n / 2];
							heap[n / 2] = inst;
						}
                    }
			}
		}
		else {
			n++;
			heap[n] = input;
			for (int t = n, k = 0; t > 1; t /= 2) {
				if (heap[t] < heap[t / 2]) {
					k = heap[t];
					heap[t] = heap[t / 2];
					heap[t / 2] = k;
				}
				else break;
			}
		}
	}
	return 0;
}
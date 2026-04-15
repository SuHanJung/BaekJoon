#include <stdio.h>
#include <malloc.h>
void change(int* n1, int* n2) {
	int a = *n1;
	*n1 = *n2;
	*n2 = a;
	return;
}

int maxHeapOut(int* maxHeap) {
	if (maxHeap[0] == 0) return 0;
	int biggest = maxHeap[1];
	maxHeap[1] = maxHeap[maxHeap[0]--];
	maxHeap[maxHeap[0] + 1] = 0;
	for (int num = 1; !(maxHeap[num] >= maxHeap[num * 2] && maxHeap[num] >= maxHeap[num * 2 + 1]);) {
		if (num * 2 == maxHeap[0] && maxHeap[num * 2] > maxHeap[num]) change(&maxHeap[num], &maxHeap[num * 2]);
		if (num * 2 >= maxHeap[0]) break;
		if (maxHeap[num * 2] > maxHeap[num * 2 + 1]) {
			change(&maxHeap[num * 2], &maxHeap[num]);
			num *= 2;
		}
		else {
			change(&maxHeap[num * 2 + 1], &maxHeap[num]);
			num = num * 2 + 1;
		}
	}
	return biggest;
}

void maxHeapIn(int* maxHeap, int input) {
	maxHeap[++maxHeap[0]] = input;
	for (int num = maxHeap[0]; num > 1; num /= 2) {
		if (maxHeap[num] > maxHeap[num / 2]) change(&maxHeap[num], &maxHeap[num / 2]);
		else break;
	}
	return;
}

int main() {
	int N;
	scanf("%d", &N);
	int* maxHeap = malloc(sizeof(int) * (N + 1));
	maxHeap[0] = 0;
	for (int t = 0, input = 0; t < N; t++) {
		scanf("%d", &input);
		if (input == 0) {
			printf("%d", maxHeapOut(maxHeap));
			printf("\n");
		}
		else {
			maxHeapIn(maxHeap, input);
		}
	}
	return 0;
}
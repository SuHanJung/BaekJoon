#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int T = 0, Q = 0, input = 0, * max_heap, * min_heap, node[1000001][2] = { 0 }, n = 0, nP = 0, nM = 0, change = 0;
	char command = 0;
	scanf("%d", &T);
	for (; T > 0; T--) {
		scanf("\n%d", &Q);
		max_heap = malloc(sizeof(int) * Q);
		min_heap = malloc(sizeof(int) * Q);
		for (; Q > 0; Q--) {
			scanf("\n%c %d", &command, &input);
			if (command == 'I') {
				node[0][0]++;
				n++;
				nP++;
				nM++;
				node[node[0][0]][0] = input;
				node[node[0][0]][1] = 1;
				max_heap[nP] = node[0][0];
				min_heap[nM] = node[0][0];
				for (int t = nP; t > 1;t /= 2) {
					if (node[max_heap[t]][0] > node[max_heap[t / 2]][0]) {
						change = max_heap[t];
						max_heap[t] = max_heap[t / 2];
						max_heap[t / 2] = change;
					}
					else break;
				}
				for (int t = nM; t > 1;t /= 2) {
					if (node[min_heap[t]][0] < node[min_heap[t / 2]][0]) {
						change = min_heap[t];
						min_heap[t] = min_heap[t / 2];
						min_heap[t / 2] = change;
					}
					else break;
				}
			}
			else if (n == 0);
			else if (input == 1) {
				for (; node[max_heap[1]][1] == 0;) {
					max_heap[1] = max_heap[nP];
					nP--;
					for (int k = 0, t = 1; t * 2 + 1 <= nP;) {
						if (node[max_heap[t * 2]][0] > node[max_heap[t * 2 + 1]][0]) {
							k = t * 2;
						}
						else k = t * 2 + 1;
						if (node[max_heap[k]][0] > node[max_heap[t]][0]) {
							change = max_heap[t];
							max_heap[t] = max_heap[k];
							max_heap[k] = change;
							t = k;
						}
						else break;
					}
				}
				node[max_heap[1]][1] = 0;
				max_heap[1] = max_heap[nP];
				n--;
				nP--;
				for (int k = 0, t = 1; t * 2 + 1 <= nP;) {
					if (node[max_heap[t * 2]][0] > node[max_heap[t * 2 + 1]][0]) {
						k = t * 2;
					}
					else k = t * 2 + 1;
					if (node[max_heap[k]][0] > node[max_heap[t]][0]) {
						change = max_heap[t];
						max_heap[t] = max_heap[k];
						max_heap[k] = change;
						t = k;
					}
					else break;
				}
			}
			else {
				for (; node[min_heap[1]][1] == 0;) {
					min_heap[1] = min_heap[nM];
					nM--;
					for (int k = 0, t = 1; t * 2 + 1 <= nM;) {
						if (node[min_heap[t * 2]][0] < node[min_heap[t * 2 + 1]][0]) {
							k = t * 2;
						}
						else k = t * 2 + 1;
						if (node[min_heap[k]][0] < node[min_heap[t]][0]) {
							change = min_heap[t];
							min_heap[t] = min_heap[k];
							min_heap[k] = change;
							t = k;
						}
						else break;
					}
				}
				node[min_heap[1]][1] = 0;
				min_heap[1] = min_heap[nM];
				n--;
				nM--;
				for (int k = 0, t = 1; t * 2 + 1 <= nM;) {
					if (node[min_heap[t * 2]][0] < node[min_heap[t * 2 + 1]][0]) {
						k = t * 2;
					}
					else k = t * 2 + 1;
					if (node[min_heap[k]][0] < node[min_heap[t]][0]) {
						change = min_heap[t];
						min_heap[t] = min_heap[k];
						min_heap[k] = change;
						t = k;
					}
					else break;
				}
			}
			command = 0;
			input = 0;
			change = 0;
		}
		if (n == 0) printf("EMPTY\n");
		else {
			for (; node[max_heap[1]][1] == 0;) {
				max_heap[1] = max_heap[nP];
				nP--;
				for (int k = 0, t = 1; t * 2 + 1 <= nP;) {
					if (node[max_heap[t * 2]][0] > node[max_heap[t * 2 + 1]][0]) {
						k = t * 2;
					}
					else k = t * 2 + 1;
					if (node[max_heap[k]][0] > node[max_heap[t]][0]) {
						change = max_heap[t];
						max_heap[t] = max_heap[k];
						max_heap[k] = change;
						t = k;
					}
					else break;
				}
			}
			for (; node[min_heap[1]][1] == 0;) {
				min_heap[1] = min_heap[nM];
				nM--;
				for (int k = 0, t = 1; t * 2 + 1 <= nM;) {
					if (node[min_heap[t * 2]][0] < node[min_heap[t * 2 + 1]][0]) {
						k = t * 2;
					}
					else k = t * 2 + 1;
					if (node[min_heap[k]][0] < node[min_heap[t]][0]) {
						change = min_heap[t];
						min_heap[t] = min_heap[k];
						min_heap[k] = change;
						t = k;
					}
					else break;
				}
			}
			printf("%d %d\n", node[max_heap[1]][0], node[min_heap[1]][0]);
		}
		free(max_heap);
		free(min_heap);
		n = 0;
		nM = 0;
		nP = 0;
		node[0][0] = 0;
	}
	return 0;
}
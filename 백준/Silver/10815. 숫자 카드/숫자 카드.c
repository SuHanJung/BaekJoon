#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int clean(int arr[], int len, int size) {
	int* answer = malloc(sizeof(int) * len);
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


int Jsort(int input[], int n) {
	for (int size = 1; n > size;) {
		size *= 2;
		clean(input, n, size);
	}
	return 0;
}

int main() {
	int n = 0, m = 0;
	scanf("%d", &n);
	int* card = malloc(sizeof(int) * n);
	for (int time = 0; time < n; time++) {
		scanf("%d", &card[time]);
	}
	Jsort(card, n);
	scanf("%d", &m);
	int ma = n - 1, mi = 0, th = 0;
	for (int instant = 0, time = 0; time < m; time++) {
		ma = n - 1, mi = 0;
		scanf("%d", &instant);
		for (; ma - mi > 2;) {
			th = (ma + mi) / 2;
			if (card[th] > instant) {
				ma = th - 1;
			}
			else {
				if (card[th] < instant) {
					mi = th + 1;
				}
				else {
					printf("1 ");
					break;
				}
			}
		}
		if (card[th] != instant) {
			for (int timet = mi; timet <= ma; timet++) {
				if (card[timet] == instant) {
					printf("1 ");
					break;
				}
				else if (timet == ma) {
					printf("0 ");
				}
			}
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int clean(int arr[], int len, int size) {
	int *answer;
	answer = malloc(sizeof(int) * len);
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
	free(answer);
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
	int m = 0, n = 0, *input, inst = 0, *map, newin = 0;
	scanf("%d", &n);
	input = malloc(sizeof(int) * n);
	map = malloc(sizeof(int) * 2 *n);
	for (int time = 0; time < 2 * n; time++) map[time] = 0;
	for (int time = 0; time < n; time++) scanf("%d", &input[time]);
	scanf("%d", &m);
	Jsort(input, n);
	map[0] = input[0];
	map[n] = 1;
	for (int time = 1; time < n; time++) {
		if (input[time] != input[time - 1]) {
			newin++;
			map[newin] = input[time];
		}
		map[newin + n]++;
	}
	for (int time = 0; time < m; time++) {
		scanf("%d", &inst);
		for (int maxin = newin, minin = 0;;) {
			if (map[(maxin + minin) / 2] == inst) {
				printf("%d ", map[n + ((maxin + minin) / 2)]);
				break;
			}
			else {
				if (map[(maxin + minin) / 2] > inst) {
					maxin = (maxin + minin) / 2;
				}
				else {
					minin = (maxin + minin) / 2;
				}
			}
			if(maxin - minin < 2){
				if (map[maxin] == inst) {
					printf("%d ", map[maxin + n]);
					break;
				}
				else if (map[minin] == inst) {
					printf("%d ", map[minin + n]);
					break;
				}
				else {
					printf("0 ");
					break;
				}
			}
		}
	}
	free(map);
	free(input);
	return 0;
}
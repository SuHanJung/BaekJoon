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
	int n[2] = { 0 }, len = 0, *input, num = 0;
	scanf("%d %d", &n[0], &n[1]);
	len = n[0] + n[1];
	input = malloc(sizeof(int) * len);
	for (int time = 0; time < len; time++) scanf("%d", &input[time]);
	Jsort(input, len);
	for (int time = 1; time < len; time++) {
		if (input[time] == input[time - 1]) num++;
	}
	printf("%d", len - num - num);
	return 0;
}
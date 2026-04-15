#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int clean(long long int arr[], int len, int size) {
	long long int answer[100000];
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


int Jsort(long long int input[], int n) {
	for (int size = 1; n > size;) {
		size *= 2;
		clean(input, n, size);
	}
	return 0;
}
int main() {
    long long int answer[100001];
    int n = 0;
    scanf("%d", &n);
    for (long long int x= 0, y = 0, t = 0; t < n; t++) {
        scanf("%lld %lld", &x, &y);
        answer[t] = ((x + 100000) * 1000000) + (y + 100000);
    }
    Jsort(answer, n);
    for (int t = 0; t < n; t++) {
        printf("%lld %lld\n", (answer[t] / 1000000) - 100000, (answer[t] % 1000000) - 100000);
    }
    return 0;
}
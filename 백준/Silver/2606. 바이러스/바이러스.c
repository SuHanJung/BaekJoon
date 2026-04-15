#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int check(int arr[][2], int k, int lines) {
	if (arr[k][1] == 1) return 0;
	arr[k][1] = 1;
	for (int t = 0; t <= lines; t++) {
		if (arr[t][0] / 1000 == k) {
			check(arr, arr[t][0] % 1000, lines);
		}
		if (arr[t][0] % 1000 == k) {
			check(arr, arr[t][0] / 1000, lines);
		}
	}
	return 0;
}

int main() {
    int arr[10000][2] = {0}, input_a = 0, input_b = 0, computers = 0, lines = 0, ans = 0;
    scanf("%d", &computers);
    scanf("%d", &lines);
	for (int t = 0; t < lines; t++) {
		scanf("%d %d", &input_a, &input_b);
		if (input_a < input_b) arr[t][0] = input_a * 1000 + input_b;
		else arr[t][0] = input_b * 1000 + input_a;
	}
	check(arr, 1, lines);
	for (int t = 0; t <= computers; t++) if (arr[t][1] == 1) ans++;
	printf("%d", ans - 1);
	return 0;
}
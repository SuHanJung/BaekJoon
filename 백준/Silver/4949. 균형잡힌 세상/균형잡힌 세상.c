#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr[100] = { 0 }, k = 1;
	char sent[101] = { 0 };
	for (;;) {
		gets(sent);
		if (sent[0] == '.') break;
		for (int time = 0; sent[time] != '.'; time++) {
			switch (sent[time]) {
			case '(':
				arr[k] = 1;
				k++;
				break;
			case ')':
				k--;
				if (arr[k] == 1) arr[k] = 0;
				else {
					k = 100;
					sent[time + 1] = '.';
				}
				break;
			case '[':
				arr[k] = 2;
				k++;
				break;
			case ']':
				k--;
				if (arr[k] == 2) arr[k] = 0;
				else {
					k = 100;
					sent[time + 1] = '.';
				}
				break;
			}
		}
		if (k == 1) printf("yes\n");
		else printf("no\n");
		for (int time = 0; time < 100; time++) {
			sent[time] = 0;
			arr[time] = 0;
			k = 1;
		}
	}
	return 0;
}
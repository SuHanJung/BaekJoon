#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n[10001] = { 0 }, t = 0, inst = 0;
	scanf("%d", &t);
	for (int time = 0; time < t; time++) {
		scanf("%d", &inst);
		n[inst]++;
	}
	for (int time = 1; t > 0; time++) {
		if (n[time] > 0) {
			for(;n[time] > 0;) {
			printf("%d\n", time);
			n[time]--;
			t--;
             }
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int N = 0, M = 0, num[10] = { 0 }, len = 0, ans = 0, com[3] = { 0 }, var = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	for (int t = 0; t < 10; t++) num[t] = 1;
	for (int t = 0, inst = 0; t < M; t++) {
		scanf("%d", &inst);
		num[inst]--;
	}
	if (N > 100) com[0] = N - 100;
	else com[0] = 100 - N;
	com[1] = N;
	if (N == 0) com[1]++;
	for (int ch = 0; com[1] <= 1000000; com[1]++) {
		ch = 0;
		for (int inst = com[1]; inst > 0; inst /= 10) {
			if (num[inst % 10] == 0) ch++;
		}
		if (ch == 0) break;
	}
	com[2] = N;
	for (int ch = 0; com[2] >= 0; com[2]--) {
		ch = 0;
		for (int inst = com[2]; inst > 0; inst /= 10) {
			if (num[inst % 10] == 0) ch++;
		}
		if (ch == 0) break;
	}
	if (com[2] == 0 && num[0] == 0) com[2]--;
	if (com[1] == 1000001);
	else {
		for (var = com[1]; var > 0; var /= 10) com[1]++;
		com[1] -= N;
	}
	if (com[2] < 0) ans = 1000000;
	else {
		ans = N - com[2];
		if(com[2] == 0) ans++;
		for (var = com[2]; var > 0; var /= 10) ans++;
	}
	if (ans > com[1]) ans = com[1];
	if (ans > com[0]) ans = com[0];
	printf("%d", ans);
	return 0;
}
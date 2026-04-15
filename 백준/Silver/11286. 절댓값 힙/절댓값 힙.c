#include <stdio.h>

int size(int a) {
	if (a >= 0) return a;
	else return 0 - a;
}

int main() {
	int input[100010] = { 0 }, val = 0, N = 0, inst = 0;
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf("%d", &val);
		if (val == 0) {
			if (input[0] == 0) printf("0\n");
			else {
				printf("%d\n", input[1]);
				input[1] = input[input[0]];
				input[input[0]] = 0;
				input[0]--;
				for (int now = 1; now * 2 + 1 <= input[0];) {
					if (size(input[now * 2]) < size(input[now * 2 + 1])) {
						if (size(input[now * 2]) < size(input[now])) {
							inst = input[now * 2];
							input[now * 2] = input[now];
							input[now] = inst;
							now *= 2;
						}
						else if (size(input[now * 2]) == size(input[now]) && input[now * 2] < input[now]) {
							inst = input[now * 2];
							input[now * 2] = input[now];
							input[now] = inst;
							now *= 2;
						}
						else break;
					}
					else if (size(input[now * 2]) == size(input[now * 2 + 1])) {
						if (input[now * 2] < input[now * 2 + 1]) {
							if (size(input[now * 2]) < size(input[now])) {
								inst = input[now * 2];
								input[now * 2] = input[now];
								input[now] = inst;
								now *= 2;
							}
							else if (size(input[now * 2]) == size(input[now]) && input[now * 2] < input[now]) {
								inst = input[now * 2];
								input[now * 2] = input[now];
								input[now] = inst;
								now *= 2;
							}
							else break;
						}
						else {
							if (size(input[now * 2 + 1]) < size(input[now])) {
								inst = input[now * 2 + 1];
								input[now * 2 + 1] = input[now];
								input[now] = inst;
								now = now * 2 + 1;
							}
							else if(size(input[now * 2 + 1]) == size(input[now]) && input[now * 2 + 1] < input[now]){
								inst = input[now * 2 + 1];
								input[now * 2 + 1] = input[now];
								input[now] = inst;
								now = now * 2 + 1;
							}
							else break;
						}
					}
					else {
						if (size(input[now * 2 + 1]) < size(input[now])) {
							inst = input[now * 2 + 1];
							input[now * 2 + 1] = input[now];
							input[now] = inst;
							now = now * 2 + 1;
						}
						else if (size(input[now * 2 + 1]) == size(input[now]) && input[now * 2 + 1] < input[now]) {
							inst = input[now * 2 + 1];
							input[now * 2 + 1] = input[now];
							input[now] = inst;
							now = now * 2 + 1;
						}
						else break;
					}
				}
				if (input[0] % 2 == 0) {
					if (size(input[input[0]]) < size(input[input[0] / 2])) {
						inst = input[input[0]];
						input[input[0]] = input[input[0] / 2];
						input[input[0] / 2] = inst;
					}
					else if (size(input[input[0]]) == size(input[input[0] / 2]) && input[input[0]] < input[input[0] / 2]) {
						inst = input[input[0]];
						input[input[0]] = input[input[0] / 2];
						input[input[0] / 2] = inst;
					}
				}
			}
		}
		else {
			input[0]++;
			input[input[0]] = val;
			for (int now = input[0]; now > 1; now /= 2) {
				if (size(input[now]) < size(input[now / 2])) {
					inst = input[now];
					input[now] = input[now / 2];
					input[now / 2] = inst;
				}
				else if (size(input[now]) == size(input[now / 2]) && input[now] < input[now / 2]) {
						inst = input[now];
						input[now] = input[now / 2];
						input[now / 2] = inst;
				}
				else break;
			}
		}
	}
	return 0;
}
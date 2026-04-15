#include <stdio.h>
int main() {
	int ans = 1, input[1000] = { 0 }, mem[1000] = { 0 }, n = 0;
	scanf("%d", &n);
	for (int time = 0; time < n; time++) scanf("%d", &input[time]);
	mem[0] = 1;
	for (int time = 0; time < n; time++) {
		if (input[time] == ans) ans++;
		else if ((mem[mem[0] - 1] == ans) && (mem[0] > 1)) {
			mem[0]--;
			mem[mem[0]] = 0;
			ans++;
            time--;
		}
		else {
			mem[mem[0]] = input[time];
			mem[0]++;
		}
	}
	for (;mem[0] > 1;) {
		if (mem[mem[0] - 1] == ans) {
			mem[0]--;
			mem[mem[0]] = 0;
			ans++;
		}
		else {
			printf("Sad");
			return 0;
		}
	}
	printf("Nice");
	return 0;
}
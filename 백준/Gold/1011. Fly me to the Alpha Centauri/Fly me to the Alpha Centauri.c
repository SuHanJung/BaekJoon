#include <stdio.h>

int main() {
	int input = 0, x = 0, y = 0, ans = 0;
	scanf("%d", &input);
	for (int time = 0; time < input; time++) {
		ans = 1;
		scanf("%d %d", &x, &y);
		for (int len = y - x;len > 0;ans++) {
			len -= ((ans + 1)/ 2);
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}
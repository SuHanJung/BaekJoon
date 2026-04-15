#include <stdio.h>

int main() {
	int ans = 1, input = 0;
	scanf("%d", &input);
	for (; ans * ans <= input; ans++);
	printf("%d", ans - 1);
	return 0;
}
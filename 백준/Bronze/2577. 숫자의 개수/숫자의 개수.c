#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int tot = 1, input = 0, ans[10] = { 0 };
	for (int time = 0; time < 3; time++) {
		scanf("%d", &input);
		tot *= input;
	}
	for (int instvar = 0,time = 0; tot > 0; time++) {
		instvar = tot % 10;
		tot /= 10;
		ans[instvar]++;
	}
	for (int time = 0; time < 10; time++) {
		printf("%d\n", ans[time]);
	}
	return 0;
}
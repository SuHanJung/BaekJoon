#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a[5] = { 0 };
	for (int count = 0, ans = 0; count < 5; count++) {
		scanf("%d", &a[count]);
		a[count] *= a[count];
		ans += a[count];
		if (count == 4) printf("%d", ans % 10);
	}
	return 0;
}
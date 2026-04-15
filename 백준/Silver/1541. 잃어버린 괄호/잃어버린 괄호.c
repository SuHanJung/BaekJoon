#include <stdio.h>

int main() {
	int n = 0, ans = -1;
	for (int inst = 0;;) {
		scanf("%d", &inst);
		n += inst;
		switch (getchar()) {
		case '+':
			break;
		case '-':
			if (ans == -1) {
				ans = n;
				n = 0;
			}
			break;
		default:
			if (ans == -1) printf("%d", n);
			else printf("%d", ans - n);
			return 0;
		}
	}
}
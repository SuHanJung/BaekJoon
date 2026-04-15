#include <stdio.h>
int main() {
	char command[7] = { 0 };
	int n = 0, input = 0, arr[21] = { 0 };
	scanf("%d", &n);
	for (int t = 0; t < n; t++) {
		scanf("%s", command);
		switch (command[1]) {
		case 'd':
			scanf("%d", &input);
			arr[input] = 1;
			break;
		case 'e':
			scanf("%d", &input);
			arr[input] = 0;
			break;
		case 'h':
			scanf("%d", &input);
			printf("%d\n", arr[input]);
			break;
		case 'o':
			scanf("%d", &input);
			arr[input]++;
			arr[input] %= 2;
			break;
		case 'l':
			for (int tt = 0; tt < 21; tt++) arr[tt] = 1;
			break;
		case 'm':
			for (int tt = 0; tt < 21; tt++) arr[tt] = 0;
			break;
		}
		input = 0;
		for (int tt = 0; tt < 7; tt++) command[tt] = 0;
	}
	return 0;
}
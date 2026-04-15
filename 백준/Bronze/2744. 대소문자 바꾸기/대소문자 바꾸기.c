#include <stdio.h>

int main() {
	char input[101] = { 0 };
	scanf("%s", input);
	for (int count = 0; input[count] != 0; count++) {
		if (input[count] < 97) printf("%c", input[count] + 32);
		else printf("%c", input[count] - 32);
	}
	return 0;
}
#include <stdio.h>

void push(int stack[]) {
	int n;
	scanf("%d", &n);
	stack[++stack[0]] = n;
	return;
}
int pop(int stack[]) {
	if (stack[0] == 0) return -1;
	else return stack[stack[0]--];
}
int size(int stack[]) {
	return stack[0];
}
int empty(int stack[]) {
	if (stack[0] == 0) return 1;
	else return 0;
}
int top(int stack[]) {
	if (stack[0] == 0) return -1;
	else return stack[stack[0]];
}
int main() {
	int N, stack[10001];
	char command[6];
	stack[0] = 0;
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf("%s", command);
		switch (command[1]) {
		case 'u':
			push(stack);
			break;
		case 'i':
			printf("%d\n", size(stack));
			break;
		case 'm':
			printf("%d\n", empty(stack));
			break;
		default:
			if (command[0] == 'p') printf("%d\n", pop(stack));
			else printf("%d\n", top(stack));
		}
	}
	return 0;
}
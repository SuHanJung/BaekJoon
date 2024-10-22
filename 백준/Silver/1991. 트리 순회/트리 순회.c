void PreorderTraversal(char input[][3]) {
	char stack[30] = { 1, 0 }, now;
	while (stack[0] > 0) {
		now = stack[stack[0]];
		printf("%c", now + 'A');
		stack[0]--;
		if (input[now][2] != '.') {
			stack[0]++;
			stack[stack[0]] = input[now][2];
		}
		if (input[now][1] != '.') {
			stack[0]++;
			stack[stack[0]] = input[now][1];
		}
	}
}

void InorderTraversal(char input[][3]) {
	int stack[30] = { 1, 0 }, now, check[30] = { 0 };
	while (stack[0] > 0) {
		now = stack[stack[0]];
		stack[0]--;
		if (check[now] == 1) {
			printf("%c", now + 'A');
			check[now] = 2;
		}
		if (check[now] == 0) {
			if (input[now][2] != '.') stack[++stack[0]] = input[now][2];
			stack[++stack[0]] = now;
			if (input[now][1] != '.') stack[++stack[0]] = input[now][1];
			check[now] = 1;
		}
	}
}

void PostorderTraversal(char input[][3]) {
	int stack[30] = { 1, 0 }, now, check[30] = { 0 };
	while (stack[0] > 0) {
		now = stack[stack[0]];
		stack[0]--;
		if (check[now] == 1) {
			printf("%c", now + 'A');
			check[now] = 2;
		}
		if (check[now] == 0) {
			stack[++stack[0]] = now;
			if (input[now][2] != '.') stack[++stack[0]] = input[now][2];
			if (input[now][1] != '.') stack[++stack[0]] = input[now][1];
			check[now] = 1;
		}
	}
}

int main() {
	int N = 0;
	char in[50] = { 0 }, input[30][3] = { 0 };
	scanf("%d", &N);
	for (int t = 0; t < N; t++) {
		scanf("%s%s%s", &in[0], &in[1], &in[2]);
		for (int tt = 0; tt < 3; tt++) {
			input[in[0] - 'A'][tt] = in[tt];
			if (in[tt] != '.') input[in[0] - 'A'][tt] -= 'A';
		}
	}
	PreorderTraversal(input);
	printf("\n");
	InorderTraversal(input);
	printf("\n");
	PostorderTraversal(input);
	return 0;
}
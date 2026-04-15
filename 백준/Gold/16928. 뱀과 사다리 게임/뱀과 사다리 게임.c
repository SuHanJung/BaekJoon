#include <stdio.h>

int main() {
	int N = 0, M = 0, ans = 0, board[200] = { 0 }, bridge[200] = { 0 }, n = 0, q[20000] = { 0 };
	scanf("%d %d", &N, &M);
	for (int t = 0; t <= 100; t++) bridge[t] = t;
	for (int t = 0; t < N + M; t++) {
		scanf("%d", &n);
		scanf("%d", &bridge[n]);
	}
	board[1] = 1;
	q[0] = 1;
	q[1] = 1;
	for (int t = 1;board[100] == 0;t++) {
		if (board[bridge[q[t] + 1]] == 0) {
			board[bridge[q[t] + 1]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 1];
		}
		if (board[bridge[q[t] + 2]] == 0) {
			board[bridge[q[t] + 2]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 2];
		}
		if (board[bridge[q[t] + 3]] == 0) {
			board[bridge[q[t] + 3]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 3];
		}
		if (board[bridge[q[t] + 4]] == 0) {
			board[bridge[q[t] + 4]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 4];
		}
		if (board[bridge[q[t] + 5]] == 0) {
			board[bridge[q[t] + 5]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 5];
		}
		if (board[bridge[q[t] + 6]] == 0) {
			board[bridge[q[t] + 6]] = board[q[t]] + 1;
			q[0]++;
			q[q[0]] = bridge[q[t] + 6];
		}
	}
	printf("%d", board[100] - 1);
	return 0;
}
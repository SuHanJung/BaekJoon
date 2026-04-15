int main() {
	int N;
	char original[3][5] = { {' ',' ','*',' ',' '}, {' ','*',' ','*',' '}, {'*','*','*','*','*'} };
	scanf("%d", &N);
	for (int oy = 1,y = oy, length = (N / 3) * 5 + N / 3 - 1; oy <= N; oy++) {
		for (int ox = 1, x = ox; ox <= length; ox++) {
			x = ox;
			y = oy;
			for (int n = N / 2; n >= 3; n /= 2) {
				if (y > n) {
					y -= n;
					if (x > 6 * n / 3) x -= 6 * n / 3;
				}
				else x -= 6 * n / 6;
			}
			if (x > 0 && x < 6 && y > 0 && y < 4) {
				x--;
				y--;
				printf("%c", original[y][x]);
			}
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
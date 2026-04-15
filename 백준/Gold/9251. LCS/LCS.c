int main() {
	int map[1001][1001] = { 0 }, t, tt;
	char n[1001] = { 0 }, input[1001] = { 0 };
	scanf("%s%s", &input[1], &n[1]);
	for (t = 1; n[t] != 0;t++) {
		for (tt = 1; input[tt] != 0; tt++) {
			if (input[tt] == n[t]) map[t][tt] = map[t - 1][tt - 1] + 1;
			else map[t][tt] = (map[t - 1][tt]  > map[t][tt - 1]) ? map[t - 1][tt] : map[t][tt - 1];
		}
	}
	printf("%d", map[t - 1][tt - 1]);
	return 0;
}
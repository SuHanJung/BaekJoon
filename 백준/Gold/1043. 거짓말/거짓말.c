int main() {
	int N, M, q[1000] = { 0 }, map[51][51] = { 0 }, people[51][51] = { 0 }, ans;
	scanf("%d%d", &N, &M);
	ans = M;
	scanf("%d", &map[0][0]);
	for (int person, t = 0; t < map[0][0]; t++) {
		scanf("%d", &person);
		map[person][0]++;
		q[++q[0]] = person;
	}
	for (int t = 0; t < M; t++) {
		scanf("%d", &people[t][0]);
		for (int tt = 1; tt <= people[t][0]; tt++)scanf("%d", &people[t][tt]);
		for (int tt = 1; tt <= people[t][0];tt++) {
			for (int ttt = tt + 1; ttt <= people[t][0]; ttt++) {
				map[people[t][tt]][people[t][ttt]] = 1;
				map[people[t][ttt]][people[t][tt]] = 1;
			}
		}
	}
	for (int t = 1; t <= q[0]; t++) {
		for (int tt = 1; tt <= N; tt++) {
			if (map[q[t]][tt] == 1 && map[tt][0] == 0) {
				map[tt][0] = 1;
				q[++q[0]] = tt;
			}
		}
	}
	for (int t = 0; t < M; t++) {
		for (int tt = 1; tt <= people[t][0]; tt++) {
			if (map[people[t][tt]][0] == 1) {
				ans--;
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
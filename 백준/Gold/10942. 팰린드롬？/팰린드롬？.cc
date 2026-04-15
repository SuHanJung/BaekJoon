#include <iostream>
using namespace std;

int map[2001][2001] = { 0 }, num[2001];

int check(int n, int m) {
	if (map[n][m] != 0) return map[n][m];
	if (n == m) {
		map[n][m] = 1;
		return 1;
	}
	else if (num[n] != num[m]) {
		map[n][m] = -1;
		return -1;
	}
	else {
		if (m - n == 1) { 
			map[n][m] = 1;
			return 1; 
		}
		else map[n][m] = check(n + 1, m - 1);
		return map[n][m];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;
	for (int t = 1; t <= N; t++) cin >> num[t];
	cin >> M;
	for (int S, E, ans; M > 0; M--) { 
		cin >> S >> E;
		ans = check(S, E);
        if (ans == -1) ans++;
		cout << ans << "\n";
	}
	return 0;
}
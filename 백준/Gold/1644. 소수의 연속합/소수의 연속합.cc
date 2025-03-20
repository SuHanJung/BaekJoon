#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, ans = 0;
	cin >> N;
	int map[4000000] = { 0 };
	int* prime = new int[N / 2];
	prime[0] = 0;
	for (int t = 2; t <= N; t++) {
		if (map[t] == 0) {
			prime[prime[0] + 1] = prime[prime[0]] + t;
			prime[0]++;
		}
		for (int tt = 1; tt * t <= N; tt++) map[tt * t] = 1;
	}
	int end = prime[0];
	prime[0] = 0;
	for (int l = 0, r = 1; r <= end;) {
		if (prime[r] - prime[l] > N)l++;
		else {
			if (prime[r] - prime[l] == N) ans++;
			r++;
		}
	}
	cout << ans;
	delete[] prime;
	prime = nullptr;
	return 0;
}
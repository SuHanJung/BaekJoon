#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, p[100001] = { 0 }, q[1000001], check[100001] = { 0 };
	cin >> N >> K;
	if (K <= N) {
		cout << N - K << "\n" << 1;
		return 0;
	}
	q[0] = 1;
	q[1] = N;
	p[N] = 1;
	check[N] = 1;
	for (int t = 1; p[K] == 0 || p[q[t]] < p[K]; t++) {
		if (q[t] * 2 <= 100000) {
			if(p[q[t] * 2] == p[q[t]] + 1) check[q[t] * 2] += check[q[t]];
			if (p[q[t] * 2] == 0) {
				check[q[t] * 2] += check[q[t]];
				p[q[t] * 2] = p[q[t]] + 1;
				q[++q[0]] = q[t] * 2;
			}
		}
		if (q[t] > 0) {
			if(p[q[t] - 1] == p[q[t]] + 1) check[q[t] - 1] += check[q[t]];
			if (p[q[t] - 1] == 0) {
				check[q[t] - 1] += check[q[t]];
				p[q[t] - 1] = p[q[t]] + 1;
				q[++q[0]] = q[t] - 1;
			}
		}
		if (q[t] < 100000) {
			if (p[q[t] + 1] == p[q[t]] + 1) check[q[t] + 1] += check[q[t]];
			if (p[q[t] + 1] == 0) {
				check[q[t] + 1] += check[q[t]];
				p[q[t] + 1] = p[q[t]] + 1;
				q[++q[0]] = q[t] + 1;
			}
		}
	}
	cout << p[K] - 1 << "\n" << check[K];
	return 0;
}
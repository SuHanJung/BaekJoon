#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K, p[100001] = {0}, q[1000000];
	cin >> N >> K;
	if (K <= N) {
		cout << N - K;
		return 0;
	}
	q[0] = 1;
	q[1] = N;
	p[N] = 1;
	for (int t = 1; p[K] == 0; t++) {
		if(q[t] != 0) for (int tt = q[t]; tt < K; tt *= 2) 
			if (p[tt * 2] == 0) {
				p[tt * 2] = p[q[t]];
				q[++q[0]] = tt * 2;
			}
		if (q[t] > 0 && p[q[t] - 1] == 0) {
			p[q[t] - 1] = p[q[t]] + 1;
			q[++q[0]] = q[t] - 1;
		}
		if (q[t] < 100000 && p[q[t] + 1] == 0) {
			p[q[t] + 1] = p[q[t]] + 1;
			q[++q[0]] = q[t] + 1;
		}
	}
	cout << p[K] - 1;
	return 0;
}
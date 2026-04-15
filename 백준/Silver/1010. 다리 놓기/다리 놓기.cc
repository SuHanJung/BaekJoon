#include <iostream>
using namespace std;

class PascalTree {
private:
	int limit, **tree;
public:
	PascalTree(int _limit) :limit(_limit) {
		tree = new int* [limit + 1];
		tree[1] = new int[(limit + 1) * (limit + 2) / 2] {0};
		for (int t = 2, now = 2; t <= limit; t++, now += t) tree[t] =  &tree[1][now];
		for (int t = 1; t <= limit; t++) {
			tree[t][0] = 1;
			tree[t][t] = 1;
		}
	}
	~PascalTree() {
		delete[] tree[1];
		delete[] tree;
		tree = nullptr;
	}
	int nCr(int n, int r) {
		if (!tree[n][r]) tree[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
		return tree[n][r];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int TC;
	cin >> TC;
	PascalTree pt(30);
	for (int N, M; TC > 0; TC--) {
		cin >> N >> M;
		cout << pt.nCr(M, N) << "\n";
	}
	return 0;
}
#include <iostream>
using namespace std;

class LCS {
private:
	int *input, *lcs, length;
public:
	void bs(int n) {
		for (int l = 1, r = length, pivot = (l + r) / 2;; pivot = (l + r) / 2) {
			if (lcs[pivot] > n) r = pivot - 1;
			else if (lcs[pivot] == n) break;
			else if (lcs[pivot + 1] > n) {
				lcs[pivot + 1] = n;
				break;
			}
			else l = pivot + 1;
		}
	}
	LCS(int n): input(new int[n+1]), lcs(new int[n]), length(0){
		input[0] = n;
		for (int t = 1; t <= n; t++) cin >> input[t];

		lcs[0] = -2100000000;
		for (int t = 1; t <= input[0]; t++) {
			if (lcs[length] < input[t]) lcs[++length] = input[t];
			else bs(input[t]);
		}
	}
	~LCS() {
		delete[] input;
		delete[] lcs;
		input = nullptr;
		lcs = nullptr;
	}
	void getLcs() {
		for (int t = 1; t <= length; t++) cout << lcs[t] << " ";
	}
	void getLength() {
		cout << length;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	LCS lcs(N);
	lcs.getLength();
	return 0;
}
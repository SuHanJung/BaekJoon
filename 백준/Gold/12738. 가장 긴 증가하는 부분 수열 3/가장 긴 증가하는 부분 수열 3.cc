#include <iostream>
using namespace std;

class LCS {
private:
	int* input, * lcs, * lcsans, length;
public:
	void bs(int t) {
		for (int l = 1, r = length, pivot = (l + r) / 2;; pivot = (l + r) / 2) {
			if (lcs[pivot] > input[t]) r = pivot - 1;
			else if (lcs[pivot] == input[t]) {
				lcsans[t] = pivot;
				break;
			}
			else if (lcs[pivot + 1] > input[t]) {
				lcs[pivot + 1] = input[t];
				lcsans[t] = pivot + 1;
				break;
			}
			else l = pivot + 1;
		}
	}
	LCS(int n): input(new int[n+1]), lcs(new int[n]), lcsans(new int[n + 1]), length(0){
		input[0] = n;
		for (int t = 1; t <= n; t++) cin >> input[t];

		lcs[0] = -2100000000;
		for (int t = 1; t <= input[0]; t++) {
			if (lcs[length] < input[t]) {
				lcs[++length] = input[t];
				lcsans[t] = length;
			}
			else bs(t);
		}
	}
	~LCS() {
		delete[] input;
		delete[] lcs;
		delete[] lcsans;
		input = nullptr;
		lcs = nullptr;
		lcsans = nullptr;
	}
	void getLcs() {
		int* ans = new int[length];
		for (int t = input[0], last = length; last > 0; t--)if (lcsans[t] == last) {
			last--;
			ans[lcsans[t] - 1] = input[t];
		}
		for (int t = 0; t < length; t++) cout << ans[t] << " ";
		delete[] ans;
		ans = nullptr;
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
#include <iostream>
using namespace std;

struct RGB {
	int d[3];
};

class DP {
private:
	int n;
	RGB* rgb;
	int run(int start) {
		int prev[3] = { 10000, 10000, 10000 };
		int minD[3];
		prev[start] = rgb[0].d[start];
		for (int t = 1; t < n; t++) {
			minD[0] = rgb[t].d[0] + ((prev[1] < prev[2]) ? prev[1] : prev[2]);
			minD[1] = rgb[t].d[1] + ((prev[0] < prev[2]) ? prev[0] : prev[2]);
			minD[2] = rgb[t].d[2] + ((prev[0] < prev[1]) ? prev[0] : prev[1]);
			for (int tt = 0; tt < 3; tt++) prev[tt] = minD[tt];
		}
		return (minD[(start + 1) % 3] < minD[(start + 2) % 3]) ? minD[(start + 1) % 3] : minD[(start + 2) % 3];
	}
public:
	DP(int _n) :n(_n), rgb(new RGB[_n]) {
		for (int t = 0; t < _n; t++) cin >> rgb[t].d[0] >> rgb[t].d[1] >> rgb[t].d[2];
	}
	~DP() {
		delete[] rgb;
		rgb = nullptr;
	}
	int getAns() {
		int ans[3] = { run(0), run(1), run(2) };
		if (ans[0] < ans[1]) return (ans[0] < ans[2]) ? ans[0] : ans[2];
		else return (ans[1] < ans[2]) ? ans[1] : ans[2];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	DP dp(n);
	cout << dp.getAns();
	return 0;
}
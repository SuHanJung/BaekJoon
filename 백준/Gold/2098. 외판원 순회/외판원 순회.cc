#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Matrix {
private:
	int row, column, *data;
public:
	Matrix(int r, int c) :row(r), column(c), data(new int[r * c] {0}) {
	}
	~Matrix(){
		delete[] data;
		data = nullptr;
	}
	int getData(int r, int c){
		return data[r * column + c];
	}
	void setData(int r, int c, int n) {
		data[r * column + c] = n;
	}
	void input() {
		for (int r = 0; r < row; r++) for (int c = 0; c < column; c++) {
			cin >> data[r * column + c];
			if (data[r * column + c] == 0) data[r * column + c] += 21000000;
		}
	}
};
Matrix* m;
class DP {
private:
	const int INF = 21000000;
	int n;
	vector<unsigned> digit;
	Matrix *d;
public:
	DP(int _n) :n(_n) {
		digit.push_back(1);
		for (int t = 1; t < n; t++) digit.emplace_back(digit.back() << 1);
		d = new Matrix((int)(digit.back() << 1), n);
		for (int t = 1; t < n; t++) d->setData(digit[t], t, m->getData(0, t));
	}
	~DP() {
		delete d;
		d = nullptr;
	}
	int dp(unsigned int visited, int last) {
		int distance = d->getData((int)visited, last);
		if (distance) return distance;

		unsigned int newVisited = visited - digit[last];
		vector <int> branch;
		for (int t = 1; t < n; t++) {
			if (visited & digit[t] && t != last) branch.push_back(dp(newVisited, t) + m->getData(t, last));
			else(branch.push_back(INF));
		}
		distance = *(min_element(branch.begin(), branch.end()));
		d->setData((int)visited, last, distance);
		return distance;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	m = new Matrix(n, n);
	m->input();
	DP *dp = new DP(n);
	cout << dp->dp((1 << n) - 1, 0);
	delete dp;
	dp = nullptr;
	delete m;
	m = nullptr;
	return 0;
}
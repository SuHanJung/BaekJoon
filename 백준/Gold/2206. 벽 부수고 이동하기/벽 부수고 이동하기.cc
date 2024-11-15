#include <iostream>
using namespace std;
static const int INF = 1000000;

class Map {
private:
	bool **input;
	int **d0, **d1, width, height;
	bool IsWall(int m, int n) {
		return input[m][n];
	}
	bool ExploreMapByWall(int m, int n, int d) {
		if (d != INF + 1 && d1[m][n] == INF) {
			d1[m][n] = d;
			return true;
		}
		return false;
	}
	bool ExploreMapByMap(int m, int n, int _d0, int _d1) {
		if (_d0 != INF + 1 && d0[m][n] == INF) {
			d0[m][n] = _d0;
			if (_d1 != INF + 1 && d1[m][n] == INF) d1[m][n] = _d1;
			return true;
		}
		else if (_d1 != INF + 1 && d1[m][n] == INF) {
			d1[m][n] = _d1;
			return true;
		}
		return false;
	}
	bool ExploreWallByMap(int m, int n, int d) {
		if (d != INF + 1 && d1[m][n] == INF) {
			d1[m][n] = d;
			return true;
		}
		return false;
	}
public:
	Map(int _width, int _height) :input(new bool* [_height]), d0(new int* [_height]), d1(new int* [_height]), width(_width), height(_height) {
		char k;
		for (int t = 0; t < _height; t++) {
			input[t] = new bool[_width];
			d0[t] = new int[_width];
			d1[t] = new int[_width];
		}
		for (int y = 0; y < _height; y++) {
			for (int x = 0; x < _width; x++) {
				cin >> k;
				if (k == '1')input[y][x] = true;
				else input[y][x] = false;
				d0[y][x] = INF;
				d1[y][x] = INF;
			}
		}
		d0[0][0] = 1;
	}
	~Map() {
		for (int t = 0; t < height; t++) {
			delete[] input[t];
			input[t] = nullptr;
			delete[] d0;
			d0 = nullptr;
			delete[] d1;
			d1 = nullptr;
		}
		delete[] input;
		input = nullptr;
		delete d0;
		d0 = nullptr;
		delete d1;
		d1 = nullptr;
	}
	void bfs() {
		int* q = new int[width * height * 2];
		q[0] = 1;
		q[1] = 0;
		for (int t = 1, n, m; t <= q[0]; t++) {
			n = q[t] / 1000;
			m = q[t] % 1000;
			if (IsWall(m, n)) {
				if (m > 0 && !IsWall(m - 1, n) && ExploreMapByWall(m - 1, n, d1[m][n] + 1)) q[++q[0]] = n * 1000 + m - 1;
				if (m < height - 1 && !IsWall(m + 1, n) && ExploreMapByWall(m + 1, n, d1[m][n] + 1)) q[++q[0]] = n * 1000 + m + 1;
				if (n > 0 && !IsWall(m, n - 1) && ExploreMapByWall(m, n - 1, d1[m][n] + 1)) q[++q[0]] = (n - 1) * 1000 + m;
				if (n < width - 1 && !IsWall(m, n + 1) && ExploreMapByWall(m, n + 1, d1[m][n] + 1)) q[++q[0]] = (n + 1) * 1000 + m;
			}
			if (m > 0) {
				if (IsWall(m - 1, n)) {
					if (ExploreWallByMap(m - 1, n, d0[m][n] + 1)) q[++q[0]] = n * 1000 + m - 1;
				}
				else if (ExploreMapByMap(m - 1, n, d0[m][n] + 1, d1[m][n] + 1)) q[++q[0]] = n * 1000 + m - 1;
			}
			if (m < height - 1) {
				if (IsWall(m + 1, n)) {
					if (ExploreWallByMap(m + 1, n, d0[m][n] + 1)) q[++q[0]] = n * 1000 + m + 1;
				}
				else if (ExploreMapByMap(m + 1, n, d0[m][n] + 1, d1[m][n] + 1)) q[++q[0]] = n * 1000 + m + 1;
			}
			if (n > 0) {
				if (IsWall(m, n - 1)) {
					if (ExploreWallByMap(m, n - 1, d0[m][n] + 1)) q[++q[0]] = (n - 1) * 1000 + m;
				}
				else if (ExploreMapByMap(m, n - 1, d0[m][n] + 1, d1[m][n] + 1)) q[++q[0]] = (n - 1) * 1000 + m;
			}
			if (n < width - 1) {
				if (IsWall(m, n + 1)) {
					if (ExploreWallByMap(m, n + 1, d0[m][n] + 1)) q[++q[0]] = (n + 1) * 1000 + m;
				}
				else if (ExploreMapByMap(m, n + 1, d0[m][n] + 1, d1[m][n] + 1)) q[++q[0]] = (n + 1) * 1000 + m;
			}
		}
		delete[] q;
		q = nullptr;
	}
	int GetAnswer() {
		if (d0[height - 1][width - 1] < d1[height - 1][width - 1]) return d0[height - 1][width - 1];
		return d1[height - 1][width - 1];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int height, width, ans;
	cin >> height >> width;
	Map map = Map(width, height);
	map.bfs();
	ans = map.GetAnswer();
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}
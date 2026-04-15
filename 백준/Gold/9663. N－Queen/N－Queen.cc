#include <iostream>
using namespace std;

class Map {
private:
	int* queen, * diagonal1, * diagonal2, answer, N;
public:
	Map(int _N):queen(new int[_N]), diagonal1(new int[_N]), diagonal2(new int[_N]),answer(0), N(_N){
		for (int t = 0; t < _N; t++) {
			queen[t] = 0;
			diagonal1[t] = 0;
			diagonal2[t] = 0;
		}
	}
	~Map() {
		delete[] queen;
		queen = nullptr;
		delete[] diagonal1;
		diagonal1 = nullptr;
		delete[] diagonal2;
		diagonal2 = nullptr;

	}
	int run() {
		for (int line = 0, d1, d2;queen[0] < N;) {
			if (queen[line] >= N) {
				queen[line] = 0;
				diagonal1[line] = 0;
				diagonal2[line] = 0;
				line--;
				queen[line]++;
			}
			else {
				d1 = line + queen[line];
				d2 = line - queen[line];
				for (int t = 0; t <= line; t++) {
					if (t == line) {
						if (line == N - 1) {
							answer++;
							queen[line]++;
						}
						else {
							diagonal1[line] = d1;
							diagonal2[line] = d2;
							line++;
						}
						break;
					}
					else if (d1 == diagonal1[t] || (d2 == diagonal2[t]) || (queen[line] == queen[t])) {
						if (queen[line] == N - 1) {
							for (int tt = line; tt < N; tt++) {
								diagonal1[tt] = 0;
								diagonal2[tt] = 0;
								queen[tt] = 0;
							}
							line--;
							queen[line]++;
						}
						else {
							queen[line]++;
						}
						break;
					}
				}
			}
		}
		return answer;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	Map map = Map(N);
	cout << map.run();
	return 0;
}
#include <iostream>
using namespace std;
static const int INF(1000000000);
	
class Node {
private:
	int* d;
public:
	Node():d(nullptr){}
	~Node() {
		delete[] d;
		d = nullptr;
	}
	void Size(int size){
		d = new int[size];
		for (int t = 0; t < size; t++) d[t] = INF;
	}
	void Update(int end, int distance){
		d[end] = (d[end] < distance) ? d[end] : distance;
	}
	int GetDistance(int end) {
		return d[end];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, s, e, d, d2;
	cin >> n >> m;
	Node* node = new Node[n];
	for (int t = 0; t < n; t++) node[t].Size(n);
	for (int t = 0; t < m; t++) {
		cin >> s >> e >> d;
		s--;
		e--;
		node[s].Update(e, d);
	}
	for (int t = 0; t < n; t++)node[t].Update(t, 0);
	for (int m = 0; m < n; m++) {
		for (s = 0; s < n; s++) {
			for (e = 0; e < n; e++) {
				d = node[s].GetDistance(m);
				d2 = node[m].GetDistance(e);
				if(d != INF && d2 != INF) node[s].Update(e, d + d2);
			}
		}
	}
	for (s = 0; s < n; s++) {
		for (e = 0; e < n; e++) {
			d = node[s].GetDistance(e);
			if (d == INF) d = 0;
			cout << d << " ";
		}
		cout << "\n";
	}
	delete[] node;
	node = nullptr;
	return 0;
}
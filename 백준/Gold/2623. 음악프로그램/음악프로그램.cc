#include <iostream>
using namespace std;

class Node {
private:
	int lock, key, * edge;
public:
	Node() :lock(0), key(0), edge(nullptr) {}
	~Node() {
		if (edge != nullptr) {
			delete[] edge;
			edge = nullptr;
		}
	}
	void addLock() {
		lock++;
	}
	void addKey() {
		key++;
	}
	void setNode() {
		edge = new int[key + 1];
		edge[0] = 0;
	}
	void addEdge(int _edge) {
		edge[++edge[0]] = _edge;
	}
	int getLock() {
		return lock;
	}
	void deLock() {
		lock--;
	}
	void useKey(int* q, Node** node) {
		for (int t = 1; t <= edge[0]; t++) {
			(*node)[edge[t]].deLock();
			if ((*node)[edge[t]].getLock() == 0) {
				q[++q[0]] = edge[t];
			}
		}
	}
};

void NodeSetter(int N, int M, Node** node) {
	*node = new Node[N + 1];
	int** input = new int* [M];
	for (int t = 0, c; t < M; t++) {
		cin >> c;
		input[t] = new int[c + 1];
		input[t][0] = c;
		for (int tt = 1; tt <= c; tt++) cin >> input[t][tt];
		for (int tt = 1; tt < c; tt++) {
			(*node)[input[t][tt]].addKey();
			(*node)[input[t][tt + 1]].addLock();
		}
	}
	for (int t = 1; t <= N; t++) (*node)[t].setNode();
	for (int t = 0; t < M; t++)
		for (int tt = 1; tt < input[t][0]; tt++) {
			(*node)[input[t][tt]].addEdge(input[t][tt + 1]);
		}
	for (int t = 0; t < M; t++) {
		delete[] input[t];
		input[t] = nullptr;
	}
	delete[] input;
	input = nullptr;
	node = nullptr;
	return;
}

void topologicalSort(Node** node, int N) {
	int* q = new int[N + 1];
	int* ans = new int[N + 1];
	ans[0] = 0;
	q[0] = 0;
	for (int t = 1; t <= N; t++) if ((*node)[t].getLock() == 0) q[++q[0]] = t;
	for (int start = 1; start <= q[0]; start++) {
		ans[++ans[0]] = q[start];
		(*node)[q[start]].useKey(q, node);
	}
	if (ans[0] == N) for (int t = 1; t <= N; t++) cout << ans[t] << "\n";
	else cout << 0;
	delete[] q;
	q = nullptr;
	delete[] ans;
	ans = nullptr;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	Node* node = nullptr;
	NodeSetter(N, M, &node);
	topologicalSort(&node, N);
	return 0;
}
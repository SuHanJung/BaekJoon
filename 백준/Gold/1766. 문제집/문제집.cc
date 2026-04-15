#include <iostream>
#include <set>
using namespace std;

class Node {
private:
	int lock, key, * edge;
public:
	Node() :lock(0), key(0) {}
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
	void useKey(set <int> &q, Node* node) {
		for (int t = 1; t <= edge[0]; t++) {
			node[edge[t]].deLock();
			if (node[edge[t]].getLock() == 0) {
				q.insert(edge[t]);
			}
		}
	}
};

Node* NodeSetter(int N, int M) {
	Node* node = new Node[N + 1];
	int* input = new int[2 * M];
	for (int t = 0; t < M; t++) {
		cin >> input[t * 2] >> input[t * 2 + 1];
		node[input[t * 2]].addKey();
		node[input[t * 2 + 1]].addLock();
	}
	for (int t = 1; t <= N; t++) node[t].setNode();
	for (int t = 0; t < M; t++)	node[input[t * 2]].addEdge(input[t * 2 + 1]);
	delete[] input;
	input = nullptr;
	return node;
}

void topologicalSort(Node* node, int N) {
	set <int> q;
	auto itor = q.begin();
	for (int t = 1; t <= N; t++) if (node[t].getLock() == 0) q.insert(t);
	for (int start = 1; start <= N; start++) {
		itor = q.begin();
		cout << *itor << " ";
		node[*itor].useKey(q, node);
		q.erase(itor);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	Node* node = NodeSetter(N, M);
	topologicalSort(node, N);
	return 0;
}
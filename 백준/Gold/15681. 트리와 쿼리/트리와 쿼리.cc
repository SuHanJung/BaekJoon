#include <iostream>
using namespace std;
class Node {
public:
	int* edge, parent = 0, subtree;
	~Node() {
			delete[] edge;
			edge = nullptr;
	}
	void set() {
		edge = new int[parent + 1];
		edge[0] = 0;
		subtree = 0;
		parent = 0;
	}
	void addEdge(int n) {
		edge[++edge[0]] = n;
	}
};
class Graph {
private:
	Node* node;
	void setParent(int n, int p) {
		node[n].parent = p;
		for (int t = 1; t <= node[n].edge[0]; t++) if (node[n].edge[t] != p) 
			setParent(node[n].edge[t], n);
	}
	int setSubtree(int n) {
		if (node[n].edge[0] != 0) {
			for (int t = 1; t <= node[n].edge[0]; t++)if (node[n].edge[t] != node[n].parent)
				node[n].subtree += setSubtree(node[n].edge[t]);
		}
		return ++node[n].subtree;
	}
public:
	Graph(int n):node(new Node[n + 1]) {
		int *edge = new int[n * 2 - 2];
		for (int t = 0; t < n * 2 - 2; t+=2) {
			cin >> edge[t] >> edge[t + 1];
			node[edge[t]].parent++;
			node[edge[t + 1]].parent++;
		}
		for (int t = 0; t <= n; t++) node[t].set();
		for (int t = 0, l, r; t < n * 2 - 2; t += 2) {
			l = edge[t];
			r = edge[t + 1];
			node[l].addEdge(r);
			node[r].addEdge(l);
		}
		delete[] edge;
		edge = nullptr;
	}
	void setRoot(int r) {
		setParent(r, r);
		node[r].subtree = 0;
		setSubtree(r);
	}
	int getQ(int q) {
		return node[q].subtree;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, R, Q;
	cin >> N >> R >> Q;
	Graph graph(N);
	graph.setRoot(R);
	for (int t = 0, q; t < Q; t++) {
		cin >> q;
		cout << graph.getQ(q) << "\n";
	}
	return 0;
}
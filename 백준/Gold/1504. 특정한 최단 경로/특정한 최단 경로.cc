#include <iostream>
using namespace std;

class Node {
private:
	int edgeMax, edgeUsing;
	int* linked;
public:
	Node(): edgeMax(0), edgeUsing(0), linked(0) {}
	~Node(){
		delete[] linked;
	}
	void nodeSet(int N) {
		edgeMax = N;
		edgeUsing = 0;
		linked = new int[N];
	}
	void addEdge(int edge) {
		if (edgeUsing == edgeMax) return;
		linked[edgeUsing] = edge;
		edgeUsing++;
	}
	bool getLinked(int n, int &_linked) {
		if (n >= edgeMax) return false;
		_linked = linked[n];
		return true;
	}
};
class Edge {
private:
	int left, right, distance;
public:
	Edge(){
		cin >> left >> right >> distance;
		left--;
		right--;
	}
	void get(int &a, int&b) {
		a = left;
		b = right;
	}
	void get(int node, int &linked, int &d) {
		d = distance;
		if (node == left) {
			linked = right;
		}
		else linked = left;
	}
	void apply(Node* node, int t) {
		node[left].addEdge(t);
		node[right].addEdge(t);
	}
	void count(int* arr) {
		arr[left]++;
		arr[right]++;
	}
};


class Graph {
public:
	int numberOfNode, numberOfEdge, *arr;
	Node* node;
	Edge* edge;
	Graph(int N, int E):numberOfNode(N), numberOfEdge(E), node(new Node[N]), edge(new Edge[E]) {
		arr = new int[N];
		for (int t = 0; t < N; t++) arr[t] = 0;
		for (int t = 0; t < E; t++) edge[t].count(arr);
		for (int t = 0; t < N; t++) node[t].nodeSet(arr[t]);
		for(int t = 0;t < E;t++) edge[t].apply(node, t);
	}
	~Graph() {
		delete[] node;
		delete[] edge;
		delete[] arr;
	}
	void bfs(int start, int *end, int size) {
		int* q = new int[numberOfNode + numberOfEdge];
		for (int t = 0; t < numberOfNode; t++) arr[t] = -1;
		arr[start] = 0;
		q[0] = 1;
		q[1] = start;
		for (int t = 1, now; t <= q[0]; t++) {
			now = q[t];
			for (int n = 0, distance, linked = 0; node[now].getLinked(n, linked); n++) {
				edge[linked].get(now, linked, distance);
				if (arr[linked] == -1 || arr[linked] > arr[now] + distance) {
					arr[linked] = arr[now] + distance;
					q[++q[0]] = linked;
				}
			}
		}
		for (int t = 0; t < size; t++) end[t] = arr[end[t]];
		delete[] q;
	}
};

int main() {
	int N, E, u, v, ans = 0, uto[3] = { 0 }, vto[2] = { 0 };
	cin >> N >> E;
	Graph graph = Graph(N, E);
	cin >> u >> v;
	u--;
	v--;
	uto[0] = vto[0] = 0;
	uto[1] = vto[1] = N - 1;
	uto[2] = v;
	graph.bfs(u, uto, 3);
	graph.bfs(v, vto, 2);
	if (uto[2] == -1) ans = -1;
	else if (uto[0] == -1 || vto[1] == -1) {
		if (uto[1] == -1 || vto[0] == -1) ans = -1;
		else ans = uto[2] + uto[1] + vto[0];
	}
	else if (uto[1] == -1 || vto[0] == -1) ans = uto[2] + uto[0] + vto[1];
	else ans = (uto[1] + vto[0] < uto[0] + vto[1]) ? uto[1] + vto[0] + uto[2] : vto[1] + uto[0] + uto[2];
	cout << ans;
	return 0;
}
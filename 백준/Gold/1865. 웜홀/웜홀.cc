#include <iostream>
using namespace std;
static const int INF(100000000);

class Edge {
private:
	int start, end, distance;
public:
	Edge() {
		cin >> start >> end >> distance;
		start--;
		end--;
	}
	~Edge() {}
	int getStart() {
		return start;
	}
	int getEnd() {
		return end;
	}
	void getInfo(int& _start, int& _end, int& _distance) {
		_start = start;
		_end = end;
		_distance = distance;
	}
	void reverse() {
		distance = 0 - distance;
	}
};


class Node {
private:
	int size, used;
	int* edgeEnd, * edgeDistance;
	int* vertax, * distance;
public:
	Node() : size(0), used(0), edgeEnd(nullptr), edgeDistance(nullptr), vertax(nullptr), distance(nullptr) {}
	~Node() {
		delete[] vertax;
		vertax = nullptr;
		delete[] distance;
		distance = nullptr;
	}
	void sizeUp() {
		size++;
	}
	void setNode() {
		edgeEnd = new int[size];
		edgeDistance = new int[size];
	}
	void addEdge(int end, int distance) {
		edgeEnd[used] = end;
		edgeDistance[used] = distance;
		used++;
	}
	void optimizing(int V) {
		int optimizedSize(size);
		int* arr = new int[V];
		for (int t = 0; t < V; t++) arr[t] = INF;
		for (int t = 0; t < size; t++) {
			if (arr[edgeEnd[t]] != INF) optimizedSize--;
			arr[edgeEnd[t]] = (arr[edgeEnd[t]] < edgeDistance[t]) ? arr[edgeEnd[t]] : edgeDistance[t];
		}
		used = 0;
		vertax = new int[optimizedSize];
		distance = new int[optimizedSize];
		for (int t = 0; t < size; t++) {
			if (arr[edgeEnd[t]] != INF) {
				vertax[used] = edgeEnd[t];
				distance[used] = arr[edgeEnd[t]];
				arr[edgeEnd[t]] = INF;
				used++;
			}
		}
		size = optimizedSize;
		delete[] arr;
		arr = nullptr;
		delete[] edgeEnd;
		edgeEnd = nullptr;
		delete[] edgeDistance;
		edgeDistance = nullptr;
	}
	bool getLinked(int t, int& n, int& dis) {
		if (t >= size) return false;
		n = vertax[t];
		dis = distance[t];
		return true;
	}
};

class Graph {
private:
	int V;
	Node* node;
public:
	Graph(int _V, int E, int W) :V(_V), node(new Node[_V]) {
		Edge* edge = new Edge[E + W];
		for (int t = E; t < E + W; t++)edge[t].reverse();
		for (int t = 0; t < E + W; t++) {
			node[edge[t].getStart()].sizeUp();
			if (t < E)node[edge[t].getEnd()].sizeUp();
		}
		for (int t = 0; t < V; t++) node[t].setNode();
		for (int t = 0, start(0), end(0), distance(0); t < E + W; t++) {
			edge[t].getInfo(start, end, distance);
			node[start].addEdge(end, distance);
			if (t < E)node[end].addEdge(start, distance);
		}
		delete[] edge;
		edge = nullptr;
		for (int t = 0; t < V; t++) node[t].optimizing(V);
	}
	~Graph() {
		delete[] node;
		node = nullptr;
	}
	bool BellmanFord() {
		int* arr = new int[V];
		for (int t = 0; t < V; t++) arr[t] = INF;
		arr[0] = 0;
		for (int re = 1; re < V; re++) {
			for (int t = 0, n, d; t < V; t++) {
				for (int tt = 0; node[t].getLinked(tt, n, d); tt++) {
					if (arr[t] + d < arr[n]) {
						arr[n] = arr[t] + d;
					}
				}
			}
		}
		for (int t = 0, n, d; t < V; t++) {
			for (int tt = 0; node[t].getLinked(tt, n, d); tt++) {
				if (arr[t] + d < arr[n]) {
					delete[] arr;
					arr = nullptr;
					return true;
				}
			}
		}
		delete[] arr;
		arr = nullptr;
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N, M, W;
	Graph* graph;
	cin >> T;
	while (T-- > 0) {
		cin >> N >> M >> W;
		graph = new Graph(N, M, W);
		if (graph->BellmanFord()) cout << "YES\n";
		else cout << "NO\n";
		delete graph;
		graph = nullptr;
	}
	return 0;
}
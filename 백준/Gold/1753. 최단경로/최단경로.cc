#include <iostream>
using namespace std;

class Edge {
public:
	int start, end, distance;
	void setEdge(int u, int v, int w) {
		start = u;
		end = v;
		distance = w;
	}
};

class Node {
private:
	int N, used;
	int* linked, * distance, * nlinked, * ndistance;
public:
	Node() : N(0), used(0), linked(nullptr), distance(nullptr), nlinked(nullptr), ndistance(nullptr) {}
	~Node() {
		//delete[] nlinked;
		nlinked = nullptr;
		//delete[] ndistance;
		ndistance = nullptr;
	}
	void plus() {
		N++;
	}
	void makeNode() {
		linked = new int[N];
		distance = new int[N];
	}
	void addEdge(int ed, int di) {
		linked[used] = ed;
		distance[used] = di;
		used++;
	}
	void cleaner(int V, int* arr) {
		if (N > 0) {
			used = N;
			for (int t = 0; t < V; t++) arr[t] = 2147483647;
			for (int t = 0; t < N; t++) {
				if (arr[linked[t]] > distance[t]) {
					if (arr[linked[t]] != 2147483647) used--;
					arr[linked[t]] = distance[t];
				}
				else used--;
			}
			nlinked = new int[used];
			ndistance = new int[used];
			for (int t = 0, tt = 0; t < N; t++) {
				if (arr[linked[t]] != -1) {
					nlinked[tt] = linked[t];
					ndistance[tt] = arr[linked[t]];
					tt++;
					arr[linked[t]] = -1;
				}
			}
			N = used;
			//delete[] linked;
			linked = nullptr;
			//delete[] distance;
			distance = nullptr;
		}
	}
	bool get(int num, int& _linked, int& _distance) {
		if (num >= N) return false;
		_linked = nlinked[num];
		_distance = ndistance[num];
		return true;
	}
};

class Graph {
private:
	Node* node;
	int V;
public:
	Graph(int _V, int _E) :node(new Node[_V]), V(_V) {
		int t(0);
		Edge* edge = new Edge[_E];
		for (int u, v, w; t < _E; t++) {
			cin >> u >> v >> w;
			u--;
			v--;
			node[u].plus();
			edge[t].setEdge(u, v, w);
		}
		for (t = 0; t < V; t++) node[t].makeNode();
		for (t = 0; t < _E; t++) node[edge[t].start].addEdge(edge[t].end, edge[t].distance);
		//delete[] edge;
		edge = nullptr;
		int* arr = new int[V];
		for (t = 0; t < V; t++) node[t].cleaner(V, arr);
		//delete[] arr;
		arr = nullptr;
	}
	~Graph() {
		//delete[] node;
		node = nullptr;
	}
	bool getDistance(int K, int _num, int& _linked, int& _distance) {
		if (K >= V) return false;
		return node[K].get(_num, _linked, _distance);
	}
};

class Heap {
private:
	int* heap, * ans;
public:
	Heap(int V, int* _ans) :heap(new int[V + 10]), ans(_ans) {
		heap[0] = 0;
	}
	~Heap() {
		//delete[] heap;
		heap = nullptr;
	}
	void input(int n) {
		heap[++heap[0]] = n;
		for (int now = heap[0]; now > 1; now /= 2) {
			if (ans[heap[now]] < ans[heap[now / 2]]) {
				heap[now] += heap[now / 2];
				heap[now / 2] = heap[now] - heap[now / 2];
				heap[now] -= heap[now / 2];
			}
			else break;
		}
	}
	int out() {
		if (heap[0] < 1) {
			ans = nullptr;
			return -1;
		}
		int n = heap[1];
		heap[1] = heap[heap[0]];
		heap[0]--;
		for (int now = 1, next = 0; now * 2 < heap[0]; now = next) {
			if (now * 2 + 1 == heap[0]) next = now * 2;
			else next = (ans[heap[now * 2]] < ans[heap[now * 2 + 1]]) ? now * 2 : now * 2 + 1;
			if (ans[heap[next]] < ans[heap[now]]) {
				heap[now] += heap[next];
				heap[next] = heap[now] - heap[next];
				heap[now] -= heap[next];
			}
			else break;
		}
		return n;
	}
};

class Dijkstra {
private:
	int K;
	int* ans;
	Heap heap;
public:
	Dijkstra(int _K, int V) :K(_K), ans(new int[V + 1]), heap(Heap(V, ans)) {
		for (int t = 0; t < V; t++) ans[t] = 2147483647;
		ans[K] = 0;
	}
	~Dijkstra() {}
	void run(Graph* graph) {
		int nod(0), distance(0), t(0), now(0);
		while (graph->getDistance(K, t++, nod, distance)) {
			ans[nod] = distance;
			heap.input(nod);
		}
		while (now >= 0) {
			t = 0;
			now = heap.out();
			if (now == -1) break;
			while (graph->getDistance(now, t++, nod, distance)) {
				if (ans[nod] > ans[now] + distance) {
					ans[nod] = ans[now] + distance;
					heap.input(nod);
				}
			}
		}
		graph = nullptr;
	}
	void printans(int V) {
		for (int t = 0; t < V; t++) if (ans[t] == 2147483647) cout << "INF\n";
		else cout << ans[t] << "\n";
		//delete[] ans;
		ans = nullptr;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, K;
	cin >> V >> E >> K;
	K--;
	Graph* graph = new Graph(V, E);
	Dijkstra* dij = new Dijkstra(K, V);
	dij->run(graph);
	dij->printans(V);
	delete dij;
	dij = nullptr;
	delete graph;
	graph = nullptr;
	return 0;
}
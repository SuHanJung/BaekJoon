#include <iostream>
using namespace std;
static const int INF(2147483647);

class Priority {
public:
	int priority, data;
	Priority(): priority(INF), data(0){}
};

class Heap {
private:
	int* arr;
	Priority* priority;
public:
	Heap(int size) :arr(new int[size * 2 + 1]), priority(new Priority[size]) {
		arr[0] = 0;
	}
	~Heap() {
		delete[] arr;
		arr = nullptr;
		delete[] priority;
		priority = nullptr;
	}
	void swap(int child) {
		priority[arr[child]].data += priority[arr[child / 2]].data;
		priority[arr[child / 2]].data = priority[arr[child]].data - priority[arr[child / 2]].data;
		priority[arr[child]].data -= priority[arr[child / 2]].data;
		arr[child / 2] += arr[child];
		arr[child] = arr[child / 2] - arr[child];
		arr[child / 2] -= arr[child];
	}
	void update(int n, int prior) {
		priority[n].priority = prior;
		if (priority[n].data == 0) input(n);
		else {
			for (int now = priority[n].data; now > 1; now /= 2) {
				if (priority[arr[now]].priority < priority[arr[now / 2]].priority) swap(now);
				else break;
			}
		}
	}
	void input(int n) {
		arr[++arr[0]] = n;
		priority[n].data = arr[0];
		for (int now = priority[n].data; now > 1; now /= 2) {
			if (priority[arr[now]].priority < priority[arr[now / 2]].priority) swap(now);
			else break;
		}
	}
	int output(){
		if (arr[0] < 1) return -1;
		int n(arr[1]);
		if(arr[0] > 1) priority[arr[0]].data = 1;
		priority[arr[1]].data = 0;
		if(arr[0] > 1) arr[1] = arr[arr[0]];
		arr[0]--;
		for (int now = 1, next = 1; now <= arr[0] / 2; now = next) {
			if (now * 2 == arr[0]) next = now * 2;
			else next = (priority[arr[now * 2]].priority < priority[arr[now * 2 + 1]].priority) ? now * 2 : now * 2 + 1;
			if (priority[next].priority < priority[now].priority) swap(next);
			else break;
		}
		return n;
	}
};

class Edge {
private:
	int start, end, distance;
public:
	Edge() {
		cin >> start >> end >> distance;
		start--;
		end--;
	}
	~Edge(){}
	int getStart() {
		return start;
	}
	void getInfo(int &_start, int &_end, int &_distance) {
		_start = start;
		_end = end;
		_distance = distance;
	}
};


class Node {
private:
	int size, used;
	int* edgeEnd, * edgeDistance;
	int* vertax, * distance;
public:
	Node(): size(0), used(0), edgeEnd(nullptr), edgeDistance(nullptr), vertax(nullptr), distance(nullptr){}
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
	bool getLinked(int t, int &n, int &dis) {
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
	Graph(int _V, int E):V(_V), node(new Node[_V]) {
		Edge* edge = new Edge[E];
		for (int t = 0; t < E; t++) node[edge[t].getStart()].sizeUp();
		for (int t = 0; t < V; t++) node[t].setNode();
		for (int t = 0, start(0), end(0), distance(0); t < E; t++) {
			edge[t].getInfo(start, end, distance);
			node[start].addEdge(end, distance);
		}
		delete[] edge;
		edge = nullptr;
		for (int t = 0; t < V; t++) node[t].optimizing(V);
	}
	~Graph() {
		delete[] node;
		node = nullptr;
	}
	int Dijkstra(int start, int end) {
		int *ans = new int[V];
		Heap heap = Heap(V);
		for (int t = 0; t < V; t++) ans[t] = INF;
		ans[start] = 0;
		heap.update(start, 0);
		for (int n = heap.output();n >= 0;n = heap.output()) {
			for (int t = 0, v = 0, dis = 0; node[n].getLinked(t, v, dis); t++) {
				if (ans[v] > ans[n] + dis) {
					ans[v] = ans[n] + dis;
					heap.update(v, ans[v]);
				}
			}
		}
		int answer(ans[end]);
		delete[] ans;
		ans = nullptr;
		return answer;
	}
};

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int N, M, start, end;
	cin >> N >> M;
	Graph graph = Graph(N, M);
	cin >> start >> end;
	start--;
	end--;
	cout << graph.Dijkstra(start, end);
	return 0;
}
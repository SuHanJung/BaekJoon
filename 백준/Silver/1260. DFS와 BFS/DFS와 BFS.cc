#include <iostream>
using namespace std;

class Node {
private:
	int size;
	int *neighbor;
	
	friend Node* NodeInitiallizer(int V, int E);
	void setNode(int _size) {
		neighbor = new int[_size];
	}
	void upload(int _neighbor) {
		neighbor[size] = _neighbor;
		size++;
	}
public:
	Node() :size(0), neighbor(nullptr) {}
	~Node() {
		delete[] neighbor;
		neighbor = nullptr;
	}
	bool getNeighbor(int index, int& _neighbor) {
		if (index >= size) return false;
		_neighbor = neighbor[index];
		return true;
	}
	int getNumberOfNeighbor() { return size; }
};

Node* NodeInitiallizer(int V, int E) {
	class Map {
	private:
		int V, *size;
		bool* map;
		bool* getIndexOfEdge(int v1, int v2) {
			return &map[(V + 1) * v1 + v2];
		}
		void sizeUp(int v1, int v2) {
			size[v1]++;
			size[v2]++;
		}
	public:
		Map(int _V) :V(_V), map(new bool[(V + 1) * (V + 1)] {0}), size(new int[V + 1] {0}) {}
		~Map() {
			delete[] map;
			delete[] size;
			map = nullptr;
			size = nullptr;
		}
		bool isEmpty(int v1, int v2) {
			return !(*getIndexOfEdge(v1, v2));
		}
		void upload(int v1, int v2) {
			if (isEmpty(v1, v2)) {
				sizeUp(v1, v2);
				*getIndexOfEdge(v1, v2) = true;
				*getIndexOfEdge(v2, v1) = true;
			}
		}
		int getSize(int v) { return size[v]; }
	};
	Node* node = new Node[V + 1];
	Map map(V);
	for (int t = 0, v1, v2; t < E; t++) {
		cin >> v1>>v2;
		map.upload(v1, v2);
	}
	for (int t = 1; t <= V; t++) {
		node[t].setNode(map.getSize(t));
		for (int index = 1; index <= V; index++)
			if (!map.isEmpty(t, index)) node[t].upload(index);
	}
	return node;
}

class Graph {
private:
	int V,E, first;
	Node* node;
public:
	Graph(int _V, int _E, int _first) :V(_V),E(_E), first(_first), node(NodeInitiallizer(_V, _E)) {}
	~Graph() {
		delete[] node;
		node = nullptr;
	}
	void DFS() {
		int* stack = new int[E*5] {1, first};
		bool* visited = new bool[V + 1] {0};
        visited[0] = true;
		for (int current; stack[0] != 0;) {
			current = stack[stack[0]];
			stack[0]--;
			if (!visited[current]) {
				visited[current] = true;
				for (int index = node[current].getNumberOfNeighbor() - 1; index >= 0; index--) {
					node[current].getNeighbor(index, stack[stack[0] + 1]);
					if (!visited[stack[stack[0]+1]]) stack[0]++;
				}
				cout << current << " ";
			}
		}
		delete[] stack;
		delete[] visited;
		stack = nullptr;
		visited = nullptr;
	}
	void BFS() {
		int* queue = new int[E * 5] {1, first};
		bool* visited = new bool[V + 1] {0};
        visited[0] = true;
		for (int current, currentIndex = 1; currentIndex <= queue[0]; currentIndex++) {
			current = queue[currentIndex];
			if (!visited[current]) {
				visited[current] = true;
				for (int index = 0; node[current].getNeighbor(index, queue[queue[0] + 1]); index++)
					if (!visited[queue[queue[0] + 1]]) queue[0]++;
				cout << current << " ";
			}
		}
		delete[] queue;
		delete[] visited;
		queue = nullptr;
		visited = nullptr;
	}
	void printNode() {
		for (int t = 1; t <= V; t++) {
			cout << "\n노드" << t << "의 이웃 목록:\n";
			for (int index = 0, neighbor; node[t].getNeighbor(index, neighbor); index++) cout << neighbor << " ";

		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, first;
	cin >> V >> E >> first;
	Graph g(V, E, first);
	g.DFS();
	cout << "\n";
	g.BFS();
	return 0;
}
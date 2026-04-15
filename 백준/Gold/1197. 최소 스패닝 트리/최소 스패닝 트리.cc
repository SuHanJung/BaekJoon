#include <iostream>
using namespace std;

class Node {
private:
	int* p;
public:
	Node(int n) :p(new int[n + 1]) {
		for (int t = 1; t <= n; t++) p[t] = t;
	}
	~Node() {
		delete[] p;
		p = nullptr;
	}
	int getP(int n) {
		if (p[n] == n) return n;
		this->p[n] = this->getP(p[n]);
		return p[n];
	}
	void merge(int parent, int child) {
		p[child] = p[parent];
	}
};

int MergeSorting(int* arr, int* &ans, int n, int cell) {
	int* storage = new int[n];
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if (arr[ans[start + left]] > arr[ans[start + cell + right]]) {
				storage[start + left + right] = ans[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = ans[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = ans[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = ans[start + cell + right];
				break;
			}
		}
	}
	if (((n - 1) / cell ) % 2 == 0) for (int t = n / (cell * 2) * cell * 2; t < n; t++) storage[t] = ans[t];
	delete[] ans;
	ans = storage;
	storage = nullptr;
	return 0;
}

void MergeSort(int* arr, int* &ans, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, ans, n, cell);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//백준 1197 푸는 중
	int V, E, ans[2] = { 0 };
	cin >> V >> E;
	int* edge[3]; // 간선 정보(가중치, 노드1, 노드2)
	edge[0] = new int[E * 3];
	edge[1] = &edge[0][E];
	edge[2] = &edge[1][E];
	int* arr = new int[E]; // 정렬을 위한 순서 배열
	for (int t = 0; t < E; t++) {
		cin >> edge[2][t] >> edge[1][t] >> edge[0][t]; // 입력받기
		arr[t] = t; // 순서 배열 초기화
	}
	MergeSort(edge[0], arr, E); // 간선 가중치 오름차순 정렬
	Node node(V);
	for (int t = 0, parent, child; ans[0] < V - 1;t++) {
		parent = node.getP(edge[1][arr[t]]);
		child = node.getP(edge[2][arr[t]]);
		if (parent != child) {
			ans[0]++;
			ans[1] += edge[0][arr[t]];
			node.merge(parent, child);
		}
	}
	cout << ans[1];
	delete[] edge[0];
	delete[] arr;
	arr = nullptr;
	edge[0] = nullptr;
	return 0;
}
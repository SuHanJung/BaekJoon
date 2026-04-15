#include <iostream>
using namespace std;

int MergeSorting(int **arr, int n, int cell) {
	int* storage = new int[n];
	for (int start = 0; start + cell < n; start += 2 * cell) {
		for (int left = 0, right = 0, end = (start + cell * 2 < n) ? cell : n - start - cell;;) {
			if ((*arr)[start + left] > (*arr)[start + cell + right]) {
				storage[start + left + right] = (*arr)[start + cell + right];
				right++;
			}
			else {
				storage[start + left + right] = (*arr)[start + left];
				left++;
			}
			if (right >= end) {
				for (; left < cell; left++) storage[start + left + right] = (*arr)[start + left];
				break;
			}
			else if (left >= cell) {
				for (; right < end; right++) storage[start + left + right] = (*arr)[start + cell + right];
				break;
			}
		}
	}
	if (n % (cell * 2) <= cell) for (int t = n - (n % (cell * 2)); t < n; t++) storage[t] = (*arr)[t];
	free(*arr);
	*arr = storage;
	return 0;
}

void MergeSort(int** arr, int n) {
	for (int cell = 1; cell < n; cell *= 2) {
		MergeSorting(arr, n, cell);
	}
	return;
}

long long int pplus(long long int a) {
	return (a < 0) ? -a:a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, ansl = 0, ansm = 1, ansr = 2, *ary;
	long long int result = 40000000000, _result;
	cin >> N;
	ary = new int[N];
	for (int t = 0; t < N; t++) cin >> ary[t];
	MergeSort(&ary, N);
	for (int l = 0; l < N - 2; l++) {
		for (int m = l + 1, r = N - 1; m < r;) {
			_result = (long long int)ary[l] + (long long int)ary[m] + (long long int)ary[r];
			if (pplus(result) > pplus(_result)) {
				ansl = l;
				ansm = m;
				ansr = r;
				result = _result;
			}
			if (_result > 0) r--;
			else if (_result == 0) {
				cout << ary[ansl] << " " << ary[ansm] << " " << ary[ansr];
				delete[] ary;
				ary = nullptr;
				return 0;
			}
			else m++;
		}
	}
	cout << ary[ansl] << " " << ary[ansm] << " " << ary[ansr];
	delete[] ary;
	ary = nullptr;
	return 0;
}
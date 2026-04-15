#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, input;
	set<int> s;
	cin >> n;
	while (n--) {
		cin >> input;
		s.emplace(input);
	}
	cout << *(s.begin()) * *(--s.end());
	return 0;
}
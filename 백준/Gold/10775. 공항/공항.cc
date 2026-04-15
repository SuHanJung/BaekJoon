#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int G, P, ap, ans = 0;
	set <int> s;
	cin >> G >> P;
	for (int t = 0; t <= G; t++) s.emplace_hint(s.end(), t);
	for (auto gate = s.begin(); P--;) {
		cin >> ap;
		gate = s.upper_bound(ap);
		gate--;
		if (gate != s.begin()) {
			s.erase(gate);
			ans++;
		}
		else {
			cout << ans;
			return 0;
		}
	}
	cout << ans;
	return 0;
}
#include <iostream>
using namespace std;

class Point {
public:
	long long int x, y;
	Point() {
		cin >> x >> y;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	long long int ans(0);
	cin >> n;
	Point* point = new Point[n];
	for (int t = 1; t < n; t++) {
		ans += point[t - 1].x * point[t].y;
		ans -= point[t - 1].y * point[t].x;
 	}
	ans += point[n - 1].x * point[0].y;
	ans -= point[n - 1].y * point[0].x;
	if (ans < 0) ans *= -1;
	printf("%lld.%lld", ans / 2, (ans % 2) * 5);
	return 0;
}
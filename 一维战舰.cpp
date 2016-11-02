#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int milk(int x, int y, int a) {
	int count = 0;
	count += (y - x - 1) / (a + 1);
	if (((y - x - 1) % (a + 1)) == a) count++;
	return count;
}

int main() {
	int n, k, a;
	cin >> n >> k >> a;
	set<int> badPoint;
	badPoint.insert(0); badPoint.insert(n + 1);
	int m; cin >> m;
	int count = milk(0, n + 1, a);
	for (int i = 1; i <= m; i++) {
		/* O(logn) */
		int x; cin >> x;
		auto it = badPoint.upper_bound(x);
		auto right = it;
		it--;
		auto left = it;
		count -= milk(*left, *right, a);
		count += (milk(*left, x, a) + milk(x, *right, a));
		badPoint.insert(x);
		if (count < k) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}

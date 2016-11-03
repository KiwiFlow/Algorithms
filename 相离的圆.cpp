#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<cmath>
#include<climits>
using namespace std;
typedef pair<int, int> LL;
LL d[50005];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		d[i].first = a + b; d[i].second = a - b;
	}
	sort(d, d + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		  auto it = lower_bound(d, d + n, LL(d[i].second,INT_MAX*-1));
		  ans += distance(d,it);
	}
	cout << ans;
	return 0;
}

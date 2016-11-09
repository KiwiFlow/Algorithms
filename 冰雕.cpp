#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<climits>
using namespace std;
typedef unsigned long long ULL;

int a[20005];
map<int, vector<int> > m;

int main() {
	int n; cin >> n;
	for (int i = 3; i <= (n / 2); i++) {
		if (n%i == 0) {
			m[i] = vector<int>(n / i,0);
		}
	}
	int not_change = 0;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		not_change += x;
		for (auto & j : m) {
			j.second[i % (n / (j.first))] += x;
		}
	}
	int ans = not_change;
	ans = max(ans, not_change);
	for (auto &val : m) {
		for (auto &v : val.second) {
			ans = max(ans, v);
		}
	}
	cout << ans;
	return 0;
}

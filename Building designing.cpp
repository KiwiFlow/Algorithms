#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;


int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n; scanf("%d", &n);
		vector<pair<int, int>> data(n);
		for (int j = 0; j < n; j++) {
			int x; scanf("%d", &x);
			data[j] = make_pair(abs(x), x > 0 ? 1 : -1);
		}
		sort(data.begin(), data.end());
		int ans = 1;
		pair<int, int> pre(data[0]);
		for (int k = 1; k < data.size(); k++) {
			if (data[k].second != pre.second) {
				ans++;
				pre = data[k];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

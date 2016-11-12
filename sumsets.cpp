#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		vector<long long> s;
		for (int i = 0; i < n; i++) {
			long long x;
			scanf("%lld", &x);
			s.push_back(x);
		}
		vector<pair<long long,pair<long long,long long>>> d;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					d.push_back(make_pair(s[i] - s[j],make_pair(i,j)));
				}
			}
		}
		sort(d.begin(), d.end());
		int ans = INT_MIN;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				long long sum = s[i] + s[j]; 
				auto itfoo = lower_bound(d.begin(), d.end(), make_pair(sum, make_pair(-1LL, -1LL)));
				auto itbar = upper_bound(d.begin(), d.end(), make_pair(sum, make_pair(11111LL, 11111LL)));
				for (auto it = itfoo; it != itbar; it++) {
					if ((*it).first == sum
						&& i != (*it).second.first && i != (*it).second.second
						&&  j != (*it).second.first && j != (*it).second.second) {
						ans = max(ans, (int)s[(*it).second.first]);
					}
				}
            }
		}
		if (ans == INT_MIN) {
			printf("no solution\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}




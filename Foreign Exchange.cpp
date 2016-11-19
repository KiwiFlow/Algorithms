#include<stdio.h>
#include<unordered_set>
#include<set>
using namespace std;

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) && n) {
		//unordered_set<pair<int, int>> exchange;
		set<pair<int, int>> exchange;
		for (int i = 0; i < n; i++) {
			pair<int, int> x;
			scanf("%d%d", &x.first, &x.second);
			if (x.first > x.second) swap(x.first, x.second);
			if (exchange.count(x)) {
				exchange.erase(x);
			}
			else {
				exchange.insert(x);
			}
		}
		if (exchange.empty()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}

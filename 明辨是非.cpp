#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
using namespace std;

const int N = 100005;
typedef pair<int, int> P;
int parent[N];

int find_root(int i) {
	return parent[i] == i ? i : parent[i] = find_root(parent[i]);
}

int main() {
	for (int i = 0; i < N; i++) parent[i] = i;
	int n;
	scanf("%d", &n);
	map<int, set<int> > diff; // x->[y1,y2,y3... !=x]
	for (int i = 0; i < n; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		x = find_root(x);
		y = find_root(y);
		if (z == 1) {
			if ((diff.count(x) && diff[x].count(y)) || (diff.count(y)&&diff[y].count(x)) ) {
				printf("NO\n");
			}
			else {
				printf("YES\n");
				if (x != y) {
					parent[x] = y;
					if (diff.count(x)) {
						if (!diff.count(y)) diff[y] = set<int>();
						for (set<int>::iterator it = diff[x].begin(); it != diff[x].end(); it++) {
							diff[y].insert(*it);
						}
					}
				}
			}
		}
		else {
			if (x != y) {
				printf("YES\n");
				if (!diff.count(x)) diff[x] = set<int>();
				if (!diff.count(y)) diff[y] = set<int>();
				diff[x].insert(y);
				diff[y].insert(x);
			}
			else {
				printf("NO\n");
			}
		}
}
return 0;
}

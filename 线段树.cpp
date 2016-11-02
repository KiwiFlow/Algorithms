#include<cstdio>
#include<algorithm>

using namespace std;
struct node {
	pair<int, int> max_sub;
	int max_prefix, max_suffix;
	node( pair<int,int> i, int j, int k) :max_sub(i), max_prefix(j), max_suffix(k) {}
};

int a[500005];
node segment_tree[1000005];

void buildTree(int n) {
	int base = n - 1;
	for (int i = 0; i < n; i++) {
		segment_tree[base + i] = node(pair<int,int>(a[i],a[i]), a[i], a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		
	}
}


/*线段树*/
int main() {
	int n, m;
	int count = 1;
	while (scanf("%d%d", &n, &m) == 2) {
		printf("Case %d:\n", count++);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[n]);
		}
		buildTree(n);
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d%d", &a, &b);


			printf("%d %d\n",query(0,a,b).x)
		}
	}
	return 0;
}

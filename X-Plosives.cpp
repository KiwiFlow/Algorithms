#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

const int N = 100005;
int parent[N];
void init() {
	for (int i = 0; i < N; i++) parent[i] = i;
}
int find_root(int i) {
	return i == parent[i] ? i : (parent[i] = find_root(parent[i]));
}

int main() {
	int x, y;
	while (scanf("%d", &x) == 1) {
		int ans = 0;
		init();
		while (x != -1) {
			scanf("%d", &y);
			x = find_root(x); y = find_root(y);
			if (x == y) ans++;
			else parent[y] = x;
			scanf("%d", &x);
		}
		printf("%d\n", ans);
	}
	return 0;
}

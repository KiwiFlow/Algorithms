#include<cstdio>
#include<stack>
#include<queue>
#include<string>
#include<iostream>

using namespace std;

const int N = 20005;
int parent[N],d[N];
void init() {
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		d[i] = 0;
	}
}
int find_root(int i) {
	if (i == parent[i]) {
		return i;
	}
	else {
		int root = find_root(parent[i]);
		d[i] += d[parent[i]];
		return parent[i] = root;
	}
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n, u, v;
		char cmd;
		scanf("%d", &n);
		init();
		while (scanf("%c",&cmd) && cmd != 'O') {
			if (cmd == 'E') {
				scanf("%d", &u);
				find_root(u);
				printf("%d\n", d[u]);
			}
			if (cmd == 'I') {
				scanf("%d %d", &u, &v);
				parent[u] = v;
				d[u] = abs(u - v) % 1000;
			}
		}
	}
	return 0;
}

#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
using namespace std;

const int MaxN = 111;
const int INF = 1e9;
int N, g[MaxN][MaxN];
void floyd() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}


int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	scanf("%d", &N);
	
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			int d;
			if (scanf("%d", &d) == 1) {
				g[i][j] = g[j][i] = d;
			}
			else {
				getchar();
				g[i][j] = g[j][i] = INF;
			}
		}
	}
	floyd();
	int ans = 0;
	for (int k = 2; k <= N; k++) {
		ans = max(ans,g[1][k]);
	}
	printf("%d", ans);
	return 0;
}

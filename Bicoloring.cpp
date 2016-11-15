#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<string.h>
std::vector<std::vector<int>> graph(205);
bool bfs(std::vector<std::vector<int>> &graph) {
	std::vector<std::pair<bool,int>> unv(graph.size(), std::make_pair(true,0));
	std::queue<int> q;
	q.push(0);
	unv[0].first = false; unv[0].second = 1;
	while (!q.empty()) {
		int qtop = q.front();
		q.pop();
		for (auto it = graph[qtop].begin(); it != graph[qtop].end(); it++) {
			if (unv[*it].first) {
				q.push(*it);
				unv[*it].first = false;
				unv[*it].second = unv[qtop].second*-1;
			}
			else {
				if (unv[*it].second == unv[qtop].second) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	//freopen("d://in.txt", "r", stdin);
	//freopen("d://out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) && n) {
		//std::vector<std::vector<int>> graph(n);
		for (auto & v : graph) {
			v.clear();
		}
		/*0 denotes empty,1 denotes red,-1 denotes black*/
		int L; scanf("%d", &L);
		for (int i = 0; i < L; i++) {
			int x, y; scanf("%d%d", &x, &y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		if (bfs(graph)) {
			printf("BICOLORABLE.\n");
		}
		else {
			printf("NOT BICOLORABLE.\n");
		}
	}
	return 0;
}









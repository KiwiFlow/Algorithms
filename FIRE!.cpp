#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<queue>
#include<climits>
using namespace std;
const int LIMIT = 10005;
int maze[LIMIT][LIMIT];
char unv[LIMIT][LIMIT];
int r = 0;
int c = 0;

void addQ(queue<pair<int, int>> &qFire,int x,int y,int lastTime){
	if (x >= 0 && x < r && y >= 0 && y < c && !unv[x][y]) {
		qFire.push(make_pair(x*c + y, lastTime + 1));
		unv[x][y] = 1;
	}
}

void fire_time(int maze[LIMIT][LIMIT], queue<pair<int, int>> &qFire) {
	while (!qFire.empty()) {
		pair<int, int> qTop = qFire.front();
		qFire.pop();
		int x = qTop.first/c;
		int y = qTop.first%c;
		maze[x][y] = qTop.second;
		addQ(qFire,x - 1, y,qTop.second);
		addQ(qFire,x + 1, y,qTop.second);
		addQ(qFire,x, y + 1,qTop.second);
		addQ(qFire,x, y - 1,qTop.second);
	}
}

bool addL(queue<pair<int, int>> &location, int x, int y,int lasttime) {
	if (!unv[x][y] && maze[x][y] > lasttime+1) {
		location.push(make_pair(x*c + y, lasttime + 1));
		unv[x][y] = 1;
		return true;
	}
	else {
		return false;
	}
}

int escape(int maze[LIMIT][LIMIT], int b_r, int b_c) {
	queue<pair<int, int>> location;
	location.push(make_pair(b_r*c + b_c, 0));
	unv[b_r][b_c] = 1;
	while (!location.empty()) {
		pair<int, int> qtop = location.front();
		location.pop();
		int x = qtop.first / c;
		int y = qtop.first % c;
		if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
			return qtop.second+1;
		}
		addL(location, x - 1, y, qtop.second);
		addL(location, x + 1, y, qtop.second);
		addL(location, x , y+1, qtop.second);
		addL(location, x , y-1, qtop.second);
	}
	return -1;
}
/*17 -> 3*/
const int int_max = 1e9;
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		queue<pair<int, int>> qFire;
		int b_r = 0 , b_c = 0;
		scanf("%d%d", &r, &c);
		for (int j = 0; j < r; j++) {
			getchar();
			for (int k = 0; k < c; k++) {
				maze[j][k] = INT_MAX;
				unv[j][k] = 0;
				int x;
				x = getchar();
				switch (x) {
				case 'J': {
					b_r = j;
					b_c = k;
					break;
				}
				case 'F': {
					qFire.push(make_pair(j*c + k, 0));
					unv[j][k] = 1;
					break;
				}
				case '#': {
					maze[j][k] = -1; //never get fire
					unv[j][k] = 1;
					break;
				}
				default: {
					break;
				}
				}
			}
		}
		fire_time(maze, qFire);
		memset(unv, 0, sizeof(unv));
		int ans = escape(maze, b_r, b_c);
		if (ans<0) {
			printf("IMPOSSIBLE\n");
		}
		else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

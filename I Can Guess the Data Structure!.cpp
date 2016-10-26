#include<cstdio>
#include<stack>
#include<queue>

using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		bool possible[3] = { true,true,true };
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		for (int i = 0; i < n; i++) {
			int type=0,value=0;
			scanf("%d %d", &type,&value);
			if (type == 1) {
				if(possible[0])	s.push(value);
				if(possible[1]) q.push(value);
				if(possible[2]) pq.push(value);
			}
			else {
				if (possible[0]) {
					if (s.empty() || s.top() != value) {
						possible[0] = false;
					}
					else {
						s.pop();
					}
				}
				if (possible[1]) {
					if (q.empty() || q.front() != value) {
						possible[1] = false;
					}
					else {
						q.pop();
					}
				}
				if (possible[2]) {
					if (pq.empty() || pq.top() != value) {
						possible[2] = false;
					}
					else {
						pq.pop();
					}
				}
			}

		}
		if (possible[0] && !possible[1] && !possible[2]) {
			printf("stack\n");
			continue;
		}
		if (!possible[0] && possible[1] && !possible[2]) {
			printf("queue\n");
			continue;
		}
		if (!possible[0] && !possible[1] && possible[2]) {
			printf("priority queue\n");
			continue;
		}
		if (!possible[0] && !possible[1] && !possible[2]) {
			printf("impossible\n");
			continue;
		}
		printf("not sure\n");
	}
	return 0;
}

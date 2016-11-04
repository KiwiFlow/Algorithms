#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
using namespace std;
typedef long long LL;
typedef pair<LL, int> P;
LL xflag = 0x1F;
LL readLL(LL state, LL index) {
	LL flag = xflag;
	return (state&(flag << (index * 5))) >> (index * 5);
}

void writeLL(LL &state, LL index, LL num) {
	if (readLL(state, index) == xflag || num < 0) {
		state |= (xflag << (5 * index));
	}
	else {
		state &= (0xFFFFFFFFFFFFFFFF ^ (xflag << (5 * index)));
		state |= (num << (5 * index));
	}
}


int main() {
	LL n ,a, b;
	cin >> n >> a >> b;
	LL initState = 0;
	LL endState = 0;
	for (int i = 0; i < n; i++) {
		LL v; cin >> v;
		writeLL(initState, i, v);
		writeLL(endState, i, xflag);
	}
	int ans = 0;
	int x = readLL(initState, 0) / b + 1;
	writeLL(initState, 0, readLL(initState, 0) - b*x);
	writeLL(initState, 1, readLL(initState, 1) - a*x);
	writeLL(initState, 2, readLL(initState, 2) - b*x);
	
	ans += x;
	if (readLL(initState, n - 1) != xflag) {
		x = readLL(initState, n - 1) / b + 1;
		writeLL(initState, n - 1, readLL(initState, n - 1) - b*x);
		writeLL(initState, n - 2, readLL(initState, n - 2) - a*x);
		writeLL(initState, n - 3, readLL(initState, n - 3) - b*x);
		ans += x;
	}
	
	queue<P> que;
	que.push(P(initState, ans));
	set<LL> r;
	r.insert(initState);
	while (!que.empty()) {
		P head = que.front();
		que.pop();
		if (head.first == endState) {
			cout << head.second;
			return 0;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (readLL(head.first, i) != xflag) {
					LL newState = head.first;
					writeLL(newState, i, readLL(newState, i) - a);
					writeLL(newState, i - 1, readLL(newState, i - 1) - b);
					writeLL(newState, i + 1, readLL(newState, i + 1) - b);
					if (!r.count(newState)) {
						que.push(P(newState, head.second + 1));
						r.insert(newState);
					}
				}
			}
		}
	}
	return 0;
}

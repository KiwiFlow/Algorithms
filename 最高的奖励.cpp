#include<vector>
#include<list>
#include<stdio.h>
#include<math.h>
#include<queue>
#include<string.h>
#include<map>
#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

pair<int,int> a[50005];
int main() {
	//freopen("d://in.txt", "r", stdin);
	//freopen("d://out.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int time; long long bonus;
		cin >> time >> bonus;
		a[i].first = time;
		a[i].second = bonus;
	}
	sort(a, a + n);
	priority_queue<int,vector<int>, greater<int>> bonusQ;
	for (int i = 0; i < n; i++) {
		if (a[i].first > bonusQ.size()) {
			bonusQ.push(a[i].second);
		}
		else {
			if (a[i].first == bonusQ.size() && a[i].second > bonusQ.top()) {
				bonusQ.pop();
				bonusQ.push(a[i].second);
			}
		}
	}
	long long ans = 0;
	while (!bonusQ.empty()) {
		ans += bonusQ.top();
		bonusQ.pop();
	}
   cout<<ans<<endl;
	return 0;
}

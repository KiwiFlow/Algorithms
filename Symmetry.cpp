#include<set>
#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		map<int, set<int>> d;
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			d[x].insert(y);
		}
		auto it = d.begin();
		auto rit = d.rbegin();
		double line = (it->first + rit->first) / 2.0;
		string sysmetry = "YES";
		for (; it != d.end() && rit != d.rend(); it++, rit++) {
			if ((it->first + rit->first) / 2.0 != line || it->second != rit->second) {
				sysmetry = "NO";
				break;
			}
		}
		cout << sysmetry << endl;
	}
	return 0;
}

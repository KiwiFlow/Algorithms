#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
int main() {
	int m, n, a, b;cin>>m>>n>>a>>b;
	set<double> ans;
	for (int i = a; i < a + n; i++) {
		for (int j = b; j < b + m; j++) {
			ans.insert(j*log2(1.0*i));
		}
	}
	cout << ans.size();
	return 0;
}

#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> a(n),b(n),c(n),d(n);
	for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	vector<int> e(n*n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			e[i*n+j] = c[i]+d[j];
		}
	}
	sort(e.begin(),e.end());
	int res = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			res += (int)distance(lower_bound(e.begin(),e.end(),-(a[i]+b[j])),upper_bound(e.begin(),e.end(),-(a[i]+b[j])));
		}
	}
	cout<<res;
	return 0;
}

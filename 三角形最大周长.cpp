#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int T;
	cin>>T;
	for(;T>0;T--){
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end());
		int i;
		for(i=n-1;i>=2;i--){
			if(a[i-2]+a[i-1]>a[i]){
				cout<<a[i-2]+a[i-1]+a[i]<<endl;
				break;
			}
		}
		if(i==1) cout<<-1<<endl;
	}
	return 0;
}

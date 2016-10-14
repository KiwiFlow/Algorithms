#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define M 1000000007
int main(){
	int m,n;
	cin>>m>>n;
	vector<long long> pre(n,1),cur(n,1);
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			cur[j] = (pre[j]+cur[j+1])%M;	
		}
		pre = cur;
	}
	cout<<cur[0];
	return 0;
}

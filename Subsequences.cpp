#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
using namespace std;
int a[100000];
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,s;
		cin>>n>>s;
		for(int j=0;j<n;j++) cin>>a[j];
		int right=0,left=0,sum=0;
		int res = INT_MAX;
		while(1){
			while(right<n && sum<s){
				sum+=a[right];
				right++;
			}
			if(sum>=s)
				res = min(res,right-left);
			else
				break;
			sum-=a[left];
			left++;
		}
		cout<<(res==INT_MAX?0:res)<<endl;
	}
	return 0;
}

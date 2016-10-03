#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
int a[100005];
bool check(int v,int n,int k){
	int i=0;
	for(int c=1;c<k;c++){
		int j=i;
		while(i<n && a[i]<a[j]+v){
			i++;
		}
		if(i==n){
			return false;
		}
	}
	return true;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(&a[0],&a[n]);
	int left = 1,right = a[n-1]+5;
	while(left < right-1){
		int mid = left + (right-left)/2;
		if(check(mid,n,k)){
			left = mid;
		}else{
			right = mid;
		}
	}
	printf("%d",left);
	return 0;
}

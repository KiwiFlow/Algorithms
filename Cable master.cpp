#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
#include<set>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;
double a[10005];
bool check(double x,int n,int k){
	int num=0;
	for(int i=0;i<n;i++){
		num += int(a[i]/x);
	}
	return num>=k;
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	double left=0,right = 0;
	for(int i=0;i<n;i++){
		scanf("%lf",&a[i]);
		right = max(right,a[i]);
	}
	
	for(int i=0;i<1000;i++){
		double mid = left + (right-left)/2;
		if(check(mid,n,k)){
			left=mid;
		}else{
			right=mid;
		}
	}
	printf("%.2f",floor(right*100)/100);
	return 0;
}

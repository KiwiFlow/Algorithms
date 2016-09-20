#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> a(N,0);
    for(int i=0;i<N;i++) cin>>a[i];
    vector<int> dp(N+1,INT_MAX);
    dp[0] = INT_MIN;
    int res = 0;
    for(int i=0;i<N;i++){
    	int left = 0,right = N;
    	while(left<right){
    		int mid = left + (right-left)/2;
    		if(dp[mid]<a[i]){
    			left = mid+1;
    		}else{
    			if(dp[mid]>a[i]){
    				right = mid;
    				
    			}else{
    				res = max(res,mid);
    				break;
    			}
    		}
    	}
    	if(left==right){
    		dp[left] = a[i];
    		res = max(res,left);
    	} 
    }
    cout<<res;
    return 0;
}

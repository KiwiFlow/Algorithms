#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#define MD 1000000007
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> a(N,0);
    for(int i=0;i<N;i++) cin>>a[i];
    vector<unsigned long long> dp(N+1,1);
    vector<int> have(100001,0);
    for(int i=1;i<=N;i++){
    	dp[i] = (dp[i-1]*2)%MD;
    	if(have[a[i-1]]>0){
    		dp[i] = (dp[i] - dp[have[a[i-1]]-1]+MD)%MD;
    	}
    	have[a[i-1]] = i;
    }
    cout<<dp[N]-1<<endl;;
    return 0;
}

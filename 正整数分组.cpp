#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> a(N,0);
    int aSum = 0;
    for(int i=0;i<N;i++){
         cin>>a[i];
         aSum+=a[i];
    }
    int Sum = aSum;
    aSum = aSum/2;
    vector<vector<int> > dp(N+1,vector<int>(aSum+1,0));
    for(int i=1;i<=N;i++){
        for(int j=1;j<=aSum;j++){
        	if(j>=a[i-1]){
        		dp[i][j] = max(dp[i-1][j],dp[i-1][j-a[i-1]]+a[i-1]);
        	}else{
        		dp[i][j] = dp[i-1][j];
        	}
        }
    }
    cout<<abs(Sum-2*dp[N][aSum]);
    return 0;
}

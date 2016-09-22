#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int> > a(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>a[i][j];
    }
    vector<vector<int> > dp(N,vector<int>(N,0));
   
    for(int i=N-1;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            dp[i][j] = a[i][j] + max(i+1<N?dp[i+1][j]:0,j+1<N?dp[i][j+1]:0);
        }
    }
    cout<<dp[0][0];
    return 0;
}

#include<string>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    string m,n;
    cin>>m>>n;
    vector<vector<int> > dp(m.size()+1,vector<int>(n.size()+1,0));
    for(int i=0;i<=m.size();i++){
        for(int j=0;j<=n.size();j++){
            if(i==0 || j==0){
                dp[i][j] = (i==0?j:i);
            }else{
                dp[i][j] = min(dp[i-1][j-1]+(m[i-1]==n[j-1]?0:1),min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
    }
    cout<<dp[m.size()][n.size()];
    return 0;
}

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int S;
    cin>>S;
    for(int i=0;i<S;i++){
        int k;
        cin>>k;
        string p;
        cin>>p;
        string q(p);
        for(int j=0;j<q.size();j++) q[j] = (q[j]=='1'?'0':'1');
        int res = 0;
        vector<int> dp(p.size(),0);
        for(int m = 0;m<=p.size()-k;m++){
            for(int dp_i=0;dp_i<dp.size();dp_i++){
                char cur;
                if(dp_i>=m && dp_i<=m+k-1){
                    cur = q[dp_i];
                }else{
                    cur = p[dp_i];
                }
                if(dp_i>0){
                       dp[dp_i] = (cur=='0'?dp[dp_i-1]+1:0);
                }else{
                       dp[dp_i] = (cur=='0'?1:0);
                }
                res = max(res,dp[dp_i]);
            }
        }
        cout<<res<<endl;
    }
    return 0;
}

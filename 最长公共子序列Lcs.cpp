#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string p,q;
    cin>>p>>q;
    vector<vector<int> > dp(p.size(),vector<int>(q.size(),0));
    for(int i=0;i<p.size();i++){
        for(int j=0;j<q.size();j++){
            if(i==0 && j==0){
                dp[i][j] = (p[0]==q[0]?1:0);
            }else{
                if(p[i]==q[j]){
                    dp[i][j] = ((i>=1&&j>=1)?dp[i-1][j-1]:0)+1;
                }else{
                    dp[i][j] = max(i>=1?dp[i-1][j]:0,j>=1?dp[i][j-1]:0);
                }
            }
        }
    }
    //cout<<dp[p.size()-1][q.size()-1]<<endl;
    string res;
    int m=p.size()-1,n=q.size()-1;
    while(m>=0 && n>=0 && dp[m][n]>0){
        if(p[m]==q[n]){
            res = p[m]+res;
            m--;
            n--;
        }else{
        	if(n==0){
        		m--;
        		continue;
        	}
        	if(m==0){
        		n--;
        		continue;
        	}
            if(dp[m][n-1]>dp[m-1][n]){
                n--;
            }else{
                m--;
            }
        }
    }
    //cout<<res.size()<<endl;
    cout<<res;
    return 0;
    
    
}

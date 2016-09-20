#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,W;
    cin>>N>>W;
    vector<int> w(N,0);
    vector<int> p(N,0);
    vector<int> c(N,0);
    long long res = 0;
    for(int i=0;i<N;i++){
        cin>>w[i]>>p[i]>>c[i];
    }
    vector<long long> dp_pre(W+1,0);
    vector<long long> dp_cur(W+1,0);
    for(int i=0;i<N;i++){
        for(int j=1;j<W+1;j++){
            if(i==0){
                dp_cur[j] = min(j/w[i],c[i])*p[i];
            }else{
                for(int k=0;k<=min(j/w[i],c[i]);k++){
                    dp_cur[j] = max(dp_cur[j],dp_pre[j-k*w[i]]+k*p[i]);
                }
            }
            res = max(res,dp_cur[j]);
        }
        dp_pre = dp_cur;
    }
    cout<<res;
    return 0;
}

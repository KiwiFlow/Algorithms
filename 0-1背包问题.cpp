#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,W;
    cin>>N>>W;
    vector<int> w(N,0);
    vector<int> p(N,0);
    long long res = 0;
    for(int i=0;i<N;i++){
        cin>>w[i]>>p[i];
    }
    
    
    vector<long long> dp_pre(W+1,0);
    vector<long long> dp_cur(W+1,0);
    for(int i=0;i<N;i++){
        for(int j=1;j<W+1;j++){
            if(i==0){
                dp_cur[j] = ((j-w[i]>=0)?p[i]:0);
            }else{
                dp_cur[j] = max(dp_pre[j],(j-w[i]>=0)?dp_pre[j-w[i]]+p[i]:0);
            }
            res = max(res,dp_cur[j]);
        }
        dp_pre = dp_cur;
    }
    cout<<res;
    return 0;
}

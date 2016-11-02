#include<iostream>
#include<map>
#include<climits>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    map<int,int> d;
    int flag = 1;
    int xflag = 0;
    for(int i=0;i<32;i++){
        if(!(x&flag)){
            xflag = (xflag|flag);
        }else{
            d[i] = 0;
        }
        flag = flag<<1;
    }
    
    for(int i=0;i<n;i++){
        int m;cin>>m;
        if(!(m&xflag)){
            int flag = 1;
            for(int j=0;j<32;j++){
                if(m&flag){
                    d[j]++;
                }
                flag = flag<<1;
            }
        }
    }
    int ans = INT_MAX;
    for(auto it = d.begin();it!=d.end();it++){
        ans = min(ans,it->second);
    }
    cout<<ans<<endl;
    return 0;
}

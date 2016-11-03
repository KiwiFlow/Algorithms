#include<iostream>
using namespace std;
typedef long long LL;
LL f[2000];
int main(){
    LL a,b,n;
    cin>>a>>b>>n;
    if(n<=2){
        cout<<1;
    }else{
        f[1]=1;f[2]=1;
        int k=3;
        for(k=3;k<300;k++){
            f[k] = ((a*f[k-1]+b*f[k-2])%7+7)%7;
            if(f[k]==f[k-1] && f[k]==1){
                break;
            }
        }
        f[0]=f[k-2];
        cout<<f[n%(k-2)];
    }
    return 0;
}

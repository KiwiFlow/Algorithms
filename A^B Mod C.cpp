#include<iostream>
using namespace std;
long long quickpow(long long x,long long y,long long mod)
{
    long long ans=1,base=x;
    while (y>0)
    {
        if (y&1) ans=ans*base%mod;
        base=base*base%mod;
        y>>=1;
    }
    return ans;
}

int main(){
    long long  x , y ,mod;
    cin >> x >> y >> mod;
    cout << quickpow(x,y,mod);
    return 0;
    
    
}

#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
typedef long long ll;
void extend_gcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(!b) d=a,x=1,y=0;
    else{
        extend_gcd(b,a%b,d,y,x);        
        y-=x*(a/b);    
    }
}


ll inv(ll a,ll mod){
    ll d,x,y;    
    extend_gcd(a,mod,d,x,y);    
    return d==1?(x+mod)%mod:-1;
}

ll combine1(ll n,ll m,ll mod){    
    ll sum=1;   
    for(ll i=1,j=n; i<=m; i++,j--)        
        sum=(sum*j%mod)*inv(i,mod)%mod;    
    return sum;
}


int main(){
	ll m,n;
	cin>>m>>n;
    ll mod = 1000000007;
	cout<<combine1(n+m-2,n-1,mod);
	return 0;
}

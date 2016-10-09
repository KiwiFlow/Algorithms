#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
ll mod_pow(ll x,ll n,ll mod){
	if(n==0) return 1;
	if(n==1) return x%mod;
	ll res = mod_pow(x,n/2,mod);
	res = (res*res)%mod;
	if(n&1) res = (res*x)%mod;
	return res;
}

bool is_prime(ll x){
	//x > 2
	for(long long i=2;i<ll(sqrt(x)+1);i++){
		if(x%i==0) return false;
	}
	return true;
}
int main(){
	while(1){
		ll n;
		cin>>n;
		if(n==0) break;
		bool flag = true;
		if(is_prime(n)){
			cout<<n<<" is normal."<<endl;
			continue;
		}
		for(ll x=2;x<n;x++){
			if(x!=mod_pow(x,n,n)){
				flag = false;
				break;
			}
		}
		if(flag){
			cout<<"The number "<<n<<" is a Carmichael number."<<endl;
	
		}else{
			cout<<n<<" is normal."<<endl;
		}
	}
	return 0;
}

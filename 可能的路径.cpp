#include<iostream>
#include<cstdio>
using namespace std;
	
long long gcd(long long a,long long b){
    if(a<b) swap(a,b);
	return b==0?a:gcd(b,a%b);
}
	
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        long long a,b,x,y;
        scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
	    cout<<(gcd(a,b)==gcd(x,y)?"Yes":"No")<<endl;
    }
    return 0;
}

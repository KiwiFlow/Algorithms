#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==2){
    	cout<<2;
    	return 0;
    }
    long long a,b=2,c=1;
    for(long long i=3;i<=n;i++){
        a = (b+c)%1000000007;
        c=b;
        b=a;
    }
    cout<<a;
    return 0;
}

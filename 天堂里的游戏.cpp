#include<iostream>
using namespace std;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        long long a,b;
        cin>>a>>b;
        cout<<(a+3*b)/gcd(a+3*b,4*a+4*b)<<"/"<<(4*a+4*b)/gcd(a+3*b,4*a+4*b)<<endl;
    }
    return 0;
}

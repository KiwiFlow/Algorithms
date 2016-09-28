#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int res = 0;
    int i=1;
    while(i<=n){
        res = res + (n/i+8)/10*i + ((n/i)%10==1?(n%i+1):0);
        i*=10;
    }
    cout<<res;
    return 0;
}

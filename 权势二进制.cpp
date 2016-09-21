#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int res=0;
    while(n>0){
        res = max(res,n%10);
        n=n/10;
    }
    cout<<res;
    return 0;
}

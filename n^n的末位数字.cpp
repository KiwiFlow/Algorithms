#include<iostream>
using namespace std;
int go(int a,int n){
    if(n==1){
        return a;
    }
    if(n%2){
        return (go(a,n/2)*go(a,n/2)*a)%10;
    }else{
        return (go(a,n/2)*go(a,n/2))%10;
    }
}
int main(){
    int n;
    cin>>n;
    int a=n%10;
    cout<<go(a,n);
    return 0;
}

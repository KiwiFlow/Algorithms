#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a = 5;
    int res = 0;
    while(n>=a){
        res += n/a;
        a*=5;
    }
    cout<<res;
}

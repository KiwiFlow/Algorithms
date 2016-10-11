#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        n = n%7;
        if(n==0 || n==2) cout<<"B"<<endl;
        else cout<<"A"<<endl;
    }
    return 0;
}

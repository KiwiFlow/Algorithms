#include<iostream>
using namespace std;
int a[1005];
int main(){
    int t;
    cin>>t;
    int res = 0;
    for(int i=0;i<t;i++){
        cin>>a[i];
        res = res^a[i];
    }
    if(res){
        cout<<"A";
    }else{
        cout<<"B";
    }
    return 0;
}

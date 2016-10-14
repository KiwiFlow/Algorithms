#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        if( (n%(k+1)) == 0){
            cout<<"B"<<endl;
        }else{
            cout<<"A"<<endl;
        }
    }
    return 0;
}

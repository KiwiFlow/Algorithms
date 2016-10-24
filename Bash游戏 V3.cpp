#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
       string n;
       cin>>n;
       int s = 0;
       for(int j=0;j<n.size();j++) s+=n[j]-'0';
       if(s%3){
           cout<<"A"<<endl;
       }else{
           cout<<"B"<<endl;
       }
    }
    return 0;
}

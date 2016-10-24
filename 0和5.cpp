#include<iostream>
#include<string>
using namespace std;
int main(){
    int five = 0,zero = 0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        j==0?(zero++):(five++);
    }
    if(zero==0){
        cout<<"-1"<<endl;
    }else{
        if(five/9){
            cout<<string((five/9)*9,'5')+string(zero,'0')<<endl;
        }else{
            cout<<"0"<<endl;
        }
    }
    return 0;
}

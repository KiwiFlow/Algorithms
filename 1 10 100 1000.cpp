#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int x;
        cin>>x;
        bool flag = false;
        for(int k=sqrt((x-1)*2);k<=sqrt((x-1)*2)+1;k++){
            if(k*(k-1) == (x-1)*2) flag = true;
        }
        if(flag) cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}

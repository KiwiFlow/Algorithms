#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int N = s.size();
    bool flag;
    if(N%2==1){
        flag = false;
    }else{
        int i=0;
        for(;i<N/2 && s[i]==s[i+N/2];i++) ;
        if(i==N/2) flag = true;
        else flag = false;
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
    return 0;
}

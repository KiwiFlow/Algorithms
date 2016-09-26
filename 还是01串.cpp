#include<string>
#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int zero_count=0;
    for(int i=0;i<s.size();i++){
        zero_count += (s[i]=='0'?1:0);
    }
    if(zero_count==s.size()){
        cout<<0;
        return 0;
    }
    int pre_zero = 0;
    for(int k=1;k<=s.size();k++){
        pre_zero += (s[k-1]=='0'?1:0);
        if(pre_zero == s.size()-k-(zero_count-pre_zero)){
            cout<<k;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}

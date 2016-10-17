#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    string t,s;
    while(cin>>s){
        cin>>t;
        int i=0,j=0;
        while(i<t.size() && j<s.size()){
            if(t[i]==s[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        if(j==s.size()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}

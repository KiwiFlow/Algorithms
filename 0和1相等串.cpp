#include<string>
#include<iostream>
#include<stack>
#include<map>
using namespace std;
int main(){
    string a;
    cin>>a;
    map<int,int> m; // #'0' - #'1'
    int zero = 0 ,one = 0;
    int ans = 0;
    for(int i=0;i<a.size();i++){
        a[i]=='0'?(++zero):(++one);
        if(zero == one) ans = max(ans,i+1);
        else{
            if(m.find(zero-one)!=m.end()){
                ans = max(ans,i-m[zero-one]);
            }else{
                m[zero-one] = i;
            }
        }
    }
    cout<<ans;
    return 0;
}

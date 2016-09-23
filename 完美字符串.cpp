#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int> c(26,0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        c[s[i]>='A'?s[i]-'A':s[i]-'a']++;
    }
    sort(c.begin(),c.end(),greater<int>());
    int factor = 26;
    int res = 0;
    for(int i=0;i<26 && c[i]>0;i++){
        res = res + c[i]*factor;
        factor--;
    }
    cout<<res;
    
    return 0;
}

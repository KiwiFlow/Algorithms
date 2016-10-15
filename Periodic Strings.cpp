#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int t;
    cin>>t;
    string s;
    for(int i=0;i<t;i++){
        cin>>s;
        for(int j=1;j<=s.size();j++){
            if(s.size()%j) continue;
            bool ok = true;
            for(int k=j;k<s.size();k++){
                if(s[k] != s[k%j]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                printf("%d\n",j);
                if(i<t-1) printf("\n");
                break;
            }
        }
    }
    return 0;
}

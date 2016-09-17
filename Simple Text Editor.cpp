#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int Q;
    cin>>Q;
    string s;
    stack<pair<int,string> > undo;
    while(Q>0){
        int t;
        cin>>t;
        //cout<<Q<<" "<<s<<endl;
        switch(t){
            case 1:{
                string m;
                cin>>m;
                s = s+m;
                undo.push(make_pair(1,m));
                break;
            }
            case 2:{
                int k;
                cin>>k;
                undo.push(make_pair(2,s.substr(s.size()-k,k)));
                s.erase(s.end()-k,s.end());
                break;
            }
            case 3:{
                int k;
                cin>>k;
                cout<<s[k-1]<<endl;
                break;
            }
            case 4:{
                pair<int,string> u = undo.top();
                undo.pop();
                if(u.first==1){
                    s.erase(s.end()-u.second.size(),s.end());
                }else{
                    s = s+u.second;
                }
                break;
            }
        }
        Q--;
    }
    return 0;
}

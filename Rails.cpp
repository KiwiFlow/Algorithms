#include<string>
#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int main() {
    int n,e;
    while(scanf("%d",&n) && n){
        while(true){
            bool flag = true;
            int head = 1;
            stack<int> s;
            scanf("%d",&e);
            if(e==0){
                cout<<endl;
                break;
            }
            for(int i=0;i<n;i++){
                if(i!=0) scanf("%d",&e);
                /*stack*/
                if(!s.empty() && s.top()==e){
                    s.pop();
                }else{
                    while(head<=n && head!=e){
                        s.push(head);
                        head++;
                    }
                    if(head<=n) head++;
                    else{
                        flag = false;
                        i++;
                        while(i<n){
                            scanf("%d",&e);
                            i++;
                        }
                        break;
                    }
                }
            }
            if(flag){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}

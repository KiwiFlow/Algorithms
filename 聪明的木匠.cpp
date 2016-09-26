#include<queue>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    priority_queue<int> q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        q.push(a*-1);
    }
    int res = 0;
    for(int i=0;i<n-1;i++){
        int r = q.top();
        q.pop();
        int t = q.top();
        q.pop();
        q.push(r+t);
        res  = res + r*-1 + t*-1;
    }
    cout<<res;
    return 0;
}

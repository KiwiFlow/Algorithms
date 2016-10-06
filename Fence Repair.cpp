#include<queue>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    long long n;
    cin>>n;
    priority_queue<long long> q;
    for(long long i=0;i<n;i++){
        long long a;
        cin>>a;
        q.push(a*-1);
    }
    long long res = 0;
    for(long long i=0;i<n-1;i++){
        long long r = q.top();
        q.pop();
        long long t = q.top();
        q.pop();
        q.push(r+t);
        res  = res + r*-1 + t*-1;
    }
    cout<<res;
    return 0;
}

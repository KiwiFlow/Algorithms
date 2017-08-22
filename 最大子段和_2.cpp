#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long ans = 0;
    int N; cin >> N;
    vector<int> arr(N,0);
    for(int i = 0; i < N ;i++){
        cin >> arr[i];
    }
    
    long long candidate = 0;
    
    for(int i = 0; i < N; i++){
        candidate = candidate >= 0 ? ( arr[i] + candidate) : arr[i];
        ans = max(ans , candidate);
    }
    
    cout << ans;
    
    

    // long long maxSubArr=0;
    // int N;
    // cin>>N;
    // vector<int> arr(N,0);
    // for(int i=0;i<N;i++){
    //     cin>>arr[i];
    // }
    // long long  pre = 0,cur = 0;
    // for( int i=0;i<N;i++){
    //     cur = pre>=0?(arr[i]+pre):arr[i];
    //     maxSubArr = max(cur,maxSubArr);
    //     pre = cur;
    // }
    // cout<<maxSubArr;
    return 0;
}

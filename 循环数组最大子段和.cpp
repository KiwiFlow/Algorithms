#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long sArr=0,maxSubArr=0,minSubArr=0;
    int N;
    cin>>N;
    vector<int> arr(N,0);
    for(int i=0;i<N;i++){
        cin>>arr[i];
        sArr+=arr[i];
    }
    long long  pre = 0,cur = 0;
    for( int i=0;i<N;i++){
        cur = pre>=0?(arr[i]+pre):arr[i];
        maxSubArr = max(cur,maxSubArr);
        pre = cur;
    }
    pre=cur=0;
    for( int i=0;i<N;i++){
        cur = pre<=0?(arr[i]+pre):arr[i];
        minSubArr = min(cur,minSubArr);
        pre = cur;
    }
    
    cout<<max(maxSubArr,sArr-minSubArr);
    return 0;
}

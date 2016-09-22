#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long maxSubArr=0;
    int N;
    cin>>N;
    vector<int> arr(N,0);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    long long  pre = 0,cur = 0;
    for( int i=0;i<N;i++){
        cur = pre>=0?(arr[i]+pre):arr[i];
        maxSubArr = max(cur,maxSubArr);
        pre = cur;
    }
    cout<<maxSubArr;
    return 0;
}

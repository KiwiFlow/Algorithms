#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxSubArray(vector<int> & a){
    int pre = a[0];
    int res = pre;
    for(int i=1;i<a.size();i++){
        int cur = max(pre,0)+a[i];
        res = max(res,cur);
        pre = cur;
    }
    return res;
}

int maxSubSequences(vector<int> & a){
    bool hasNN = false;
    int res = 0;
    int maxNeg = INT_MIN;
    for(int i=0;i<a.size();i++){
        if(a[i]>=0){
            hasNN = true;
            res+=a[i];
        }else{
            maxNeg = max(maxNeg,a[i]);
        }
    }
    if(hasNN) return res;
    else return maxNeg;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        vector<int> a(N);
        for(int j=0;j<N;j++) cin>>a[j];
        cout<<maxSubArray(a)<<" "<<maxSubSequences(a)<<endl;
    }
    return 0;
}

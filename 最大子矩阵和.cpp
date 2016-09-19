#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int M,N;
    cin>>M>>N;
    vector<vector<int> > a(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>a[i][j];
        }
    }
    long long res = a[0][0];
    vector<long long> c(M,0);
    for(int i=0;i<N;i++){
        for(int k=0;k<M;k++) { c[k]=0; }
        for(int j=i;j<N;j++){
            for(int k=0;k<M;k++){
                c[k] = c[k] + a[j][k];
            }
            long long pre = 0,cur = 0;
            for(int t=0;t<M;t++){
                cur = pre>=0?(c[t]+pre):c[t];
                res = max(res,cur);
                pre = cur;
            }
        }
    }
    cout<<res;
    return 0;
}

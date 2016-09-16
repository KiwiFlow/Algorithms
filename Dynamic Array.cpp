#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N,Q;
    cin>>N>>Q;
    int lastAns = 0;
    vector<vector<int>> seqList(N,vector<int>());
    while(Q>0){
        int a,x,y;
        cin>>a>>x>>y;
        if(a==1){
            seqList[(x^lastAns)%N].push_back(y);
        }else{
            int size = seqList[(x^lastAns)%N].size();
            lastAns = seqList[(x^lastAns)%N][y%size];
            cout<<lastAns<<endl;
        }
        Q--;
    }
    return 0;
}

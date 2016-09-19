#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        cin>>N;
        vector<int> prefixSum(N,0);
        int a;
        for(int j=0;j<N;j++){
            cin>>a;
            if(j==0) prefixSum[j]=a;
            else prefixSum[j] = a + prefixSum[j-1]; 
        }
        int flag = false;
        for(int j=0;j<N;j++){
            if(j==0 || j==N-1){
                if(prefixSum[N-1]-prefixSum[0]==0 || prefixSum[N-2]==0){
                    flag = true;
                    break;
                }
            }else{
                if(prefixSum[j-1]==prefixSum[N-1]-prefixSum[j]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

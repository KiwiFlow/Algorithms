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
        int N,M,S;
        cin>>N>>M>>S;
        cout<<(((S+M%N-1)%N)==0?N:((S+M%N-1)%N))<<endl;

    }
        
    return 0;
}

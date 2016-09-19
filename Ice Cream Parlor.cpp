#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n;
        map<int,int> r;
        cin>>m>>n;
        for(int j=1;j<=n;j++){
            int a;
            cin>>a;
            if(r.find(m-a)!=r.end()){
                cout<<r[m-a]<<" "<<j<<endl;
            }else{
                r[a] = j; 
            }
        }
    }
    return 0;
}

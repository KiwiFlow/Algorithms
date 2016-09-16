#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    map<string,int> count;
    while(N>0){
        string s;
        cin>>s;
        count[s]++;
        N--;
    }
    int Q;
    cin>>Q;
    while(Q>0){
        string t;
        cin>>t;
        cout<<count[t]<<endl;
        Q--;
    }
    return 0;
}

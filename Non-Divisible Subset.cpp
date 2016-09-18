#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin>>n>>k;
    vector<int> arr(k,0);
    int res = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr[a%k]++;
    }
    for(int i=0;i<=k/2;i++){
        if((k-i)%k == i){
            res = res + (arr[i]?1:0);
        }else{
            res = res + max(arr[i],arr[k-i]);
        }
    }
    cout<<res<<endl;
    return 0;
}

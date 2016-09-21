#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    long long energe_next = 0,cur = 0;
    long long zero = 0;
    for(int i=n-1;i>=0;i--){
        cur = max(energe_next-a[i],zero);
        energe_next = cur;
    }
    cout<<cur;
    return 0;
}

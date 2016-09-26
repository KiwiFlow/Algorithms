#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long go(vector<int> &a,int n){
    sort(a.begin(),a.end());
    int mid = a[(n/2)];
    //cout<<mid<<endl;
    long long rr = 0;
    for(int i=0;i<n;i++) rr += abs(mid-a[i]);
    return rr;
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0),b(n,0),c(n,0);
   // vector<int> b(n,0);
   // vector<int> c(n,0);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
    cout<<go(a,n)+go(b,n)+go(c,n);
    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int mid = a[(n/2)];
    //cout<<mid<<endl;
    long long rr = 0;
    for(int i=0;i<n;i++) rr += abs(mid-a[i]);
    cout<<rr;
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    long long sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i]+a[j])/(a[i]*a[j])){
                sum += (a[i]+a[j])/(a[i]*a[j]);
            }else{
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}

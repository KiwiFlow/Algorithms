#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
long long guess(vector<long long> &a,vector<long long> &b,long long mid){
    long long order = 0;
    for(int i=a.size()-1;i>=0;i--){
        vector<long long>::iterator x = lower_bound(b.begin(),b.end(),(mid/a[i])+(mid%a[i]?1:0));
        order = order + (long long)distance(x,b.end());
    }
    return order;
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i]>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    long long  left = a[0]*b[0], right = a[n-1]*b[n-1];
    //guess the value of Kth number
    
    long long res=0;
    while(left <= right){
        long long mid = left + (right - left)/2;
        long long order = guess(a,b,mid);
        if(order >=  k){
        	res = max(res,mid); // reality >= the guess
            left = mid+1;
        }else{
             right = mid-1;
        }
    }
    cout<<res;
    return 0;
}

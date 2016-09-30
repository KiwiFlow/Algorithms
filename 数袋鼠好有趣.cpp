#include<iostream>
#include<algorithm>
using namespace std;

int a[500005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int ans = 0;
    int *begin = &a[(n-1)/2+1];
    for(int i=0;i<=(n-1)/2;i++){
        int * p = lower_bound(begin,&a[n],a[i]*2);
        if(p==&a[n]){
            break;
        }else{
            ans++;
            begin=p+1;
        }
    }
    
    cout<<n-ans;
    return 0;
}

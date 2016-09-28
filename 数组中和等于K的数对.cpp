#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int k,n;
    cin>>k>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    int left = 0,right = n-1;
    bool flag = false;
    while(left<right){
        if(a[left]+a[right]>k){
            right--;
        }else{
            if(a[left]+a[right]<k){
                left++;
            }else{
                cout<<a[left]<<" "<<a[right]<<endl;
                left++;
                flag = true;
            }
        }
    }
    if(!flag) cout<<"No Solution";
    return 0;
}

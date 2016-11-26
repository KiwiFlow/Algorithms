#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(auto &v:arr){
            cin>>v;
        }
        sort(arr.begin(),arr.end());
        int ret = 0;
        int mid = arr[arr.size()/2];
        for(int i=0;i<arr.size();i++){
            ret += abs(arr[i]-mid);
        }
        cout<<ret<<endl;
    }
    return 0;
}

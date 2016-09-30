#include<iostream>
using namespace std;
int a[30];
bool dfs(int i,int sum,int n,int k){
    if(i==n){
        return sum==k?true:false;
    }else{
        if(dfs(i+1,sum,n,k)){
            return true;
        }
        if(dfs(i+1,sum+a[i],n,k)){
            return true;
        }
        return false;
    }
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    if(dfs(0,0,n,k)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

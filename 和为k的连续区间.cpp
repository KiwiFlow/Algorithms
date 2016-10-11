#include<cstdio>
#include<iostream>
int a[10005];
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int i=1,j=2;
    bool flag = false;
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=i;j<=n;j++){
            sum+=a[j];
            if(sum==k){
                cout<<i<<" "<<j;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    if(!flag) cout<<"No Solution";
    return 0;
}

/*#include<iostream>
using namespace std;
int a[50005];
int main(){
    int n,m;
    cin>>n>>m;
    int tail = n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for(int i=0;i<m;i++){
        int r;
        cin>>r;
        
        int k=0;
        while(k<tail && r<=a[k]){
            k++;
        }
        if(k<1) break;
        tail = k-1;
        ans++;
    }
    cout<<ans;
    return 0;
}*/
#include<iostream>
#include<climits>
using namespace std;
int a[50005];
int main(){
    int n,m;
    cin>>n>>m;
    a[0] = INT_MAX;
    int in = 1;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        if(p<=a[in-1]){
            a[in]=p;
            in++;
        }
    }
    in--;
    int ans = 0;
    for(int i=0;i<m;i++){
        int r;
        cin>>r;
        while(in>=1 && r>a[in]){
            in--;
        }
        if(in<1) break;
        in--;
        ans++;
    }
    cout<<ans;
    return 0;
}

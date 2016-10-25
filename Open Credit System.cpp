#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int ans = INT_MIN;
        int curMax;
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            if(j==0){
                curMax = x;
            }else{
                ans = max(ans,curMax-x);
                curMax = max(curMax,x);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

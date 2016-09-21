#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    
    int up = a.size();
    int low = 0;
    int couple = 0;
    while(true){
        bool found = false;
        int i;
        for(i=up-1;i>low;i--){
            if(a[low]+a[i]<=m){
                found=true;
                break;
            }
        }
        if(found){
        	low++;
	        up=i;
	        couple++;
        }else{
        	break;
        }
    }
    cout<<n-couple;
    return 0;
}

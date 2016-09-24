#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<iterator>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> data;
    int res=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a-i>0){
            data.push_back(a-i);
        }else{
            res++;
        }
    }
    
    if(data.size()>0){
    	vector<int> dp(data.size(),INT_MAX);
	    dp[0] = data[0];
	    int LIS = 1;
	    for(int i=1;i<data.size();i++){
	        vector<int>::iterator x = upper_bound(dp.begin(),dp.end(),data[i]);
	        *x = data[i];
	        int d = distance(dp.begin(),x);
	        LIS = max(LIS,d+1);
	    }
	    cout<<res+data.size()-LIS;
    }else{
    	cout<<res;
    }
    return 0;
}

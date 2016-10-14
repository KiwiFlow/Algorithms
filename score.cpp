#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int T;
    cin>>T;
    
    for(int i=0;i<T;i++){
    	string s;
    	cin>>s;
    	int ans = 0;
    	int nums = 1;
    	for(int j=0;j<s.size();j++){
    		if(s[j]=='O'){
    			ans += nums;
    			nums++;
    		}else{
    			nums = 1;
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}

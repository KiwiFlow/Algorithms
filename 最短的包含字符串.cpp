#include<iostream>
#include<climits>
#include<string>
#include<vector>
using namespace std;

int main(){
    string a;
    cin>>a;
    int res = INT_MAX;
    int left = 0,right = 0;
    //cout<<a.size()<<endl;
    vector<int> c(26,0);
    int flag = 0;
    while(right < a.size()){
        while(right < a.size() && flag != 0x3FFFFFF){
            flag = flag | (1<<(a[right]-'A'));
            c[a[right]-'A']++;
            right++;
        }
        
        if(flag!=0x3FFFFFF) break;
        
        do{
        	res=min(res,right-left);
        	c[a[left]-'A']--;
        	left++;
        }while(c[a[left-1]-'A']);
        flag = flag ^ (1<<(a[left-1]-'A'));
    }
    
    if(res==INT_MAX){
        cout<<"No Solution";
    }else{
        cout<<res;
    }
    return 0;
}

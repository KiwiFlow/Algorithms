#include<vector>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > ss;
    int res = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(ss.empty() || a<ss[ss.size()-1].first){
            ss.push_back(make_pair(a,i));
        }else{
            int left = 0,right = ss.size()-1;
            int mid=0;
            while(left <= right){
                mid = left + (right-left)/2;
                if(ss[mid].first > a){
                    left = mid+1;
                }else{
                    if(mid==0 || ss[mid-1].first > a){
                        break;
                    }else{
                        right = mid-1;
                    }
                    
                }
            }
            res = max(res,i-ss[mid].second);
            
            /*int j = ss.size()-1;
            while(j>=0 && a>=ss[j].first){
                res = max(res,i-ss[j].second);
                j--;
            }*/
        }
    }
    cout<<res;
    return 0;
}

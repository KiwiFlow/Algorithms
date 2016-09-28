#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int> > getK(int left,vector<int> & a,int k){
    int right = a.size()-1;
    vector<pair<int,int> > res;
    while(left<right){
        if(a[left]+a[right]>k){
            right--;
        }else{
            if(a[left]+a[right]<k){
                left++;
            }else{
                res.push_back(make_pair(a[left],a[right]));
                left++;
            }
        }
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    bool flag = false;
    for(int i=0;i<n;i++){
        vector<pair<int,int> >  res = getK(i+1,a,-1*a[i]);
        if(!res.empty()){
            flag = true;
            for(int j=0;j<res.size();j++){
                cout<<a[i]<<" "<<res[j].first<<" "<<res[j].second<<endl;
            }
        }
    }
   
    if(!flag) cout<<"No Solution";
    return 0;
}

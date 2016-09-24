#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;
struct Comp{
    bool operator()(pair<int,int> const& m0,pair<int,int> const& m1) const {
        return m0.second > m1.second;
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> b(n,0);
    for(int i=0;i<n;i++) cin>>b[i];
    sort(b.begin(),b.end());
    
    vector<pair<int,int> > arrow(m);
    for(int i=0;i<m;i++){
        cin>>arrow[i].first>>arrow[i].second;
    }
    sort(arrow.begin(),arrow.end());
    
    int a_index = m-1;
    int flag = 1;
    int res = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,Comp> price;
    for(int i=n-1;i>=0;i--){
        while(a_index>=0 && arrow[a_index].first >= b[i] ){
            price.push(make_pair(arrow[a_index].first,arrow[a_index].second));
            a_index--;
        }
        if(!price.empty()){
            res += price.top().second;
            price.pop();
        }else{
            flag = 0;
            break;
        }
    }
        
    if(flag)
        cout<<res;
    else
        cout<<"No Solution";
    return 0;
}

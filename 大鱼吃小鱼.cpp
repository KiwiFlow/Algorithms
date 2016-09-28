#include<iostream>
#include<queue>
using namespace std;
struct Comp1{
    bool operator()(pair<int,int> const& m0,pair<int,int> const& m1) const {
        return m0.first > m1.first;
    }
};

struct Comp2{
    bool operator()(pair<int,int> const& m0,pair<int,int> const& m1) const {
        return m0.first < m1.first;
    }
};

int main(){
    int n;
    cin>>n;
    vector<pair<int,int> > fish(n);
    for(int i=0;i<n;i++) cin>>fish[i].first>>fish[i].second;
    int leftCount = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,Comp1> rightFish;
    for(int i=0;i<n;i++){
        if(fish[i].second==1){
            rightFish.push(make_pair(i,fish[i].first));
        }else{
            while(!rightFish.empty() && fish[i].first > rightFish.top().second){
                rightFish.pop();
            }
            if(rightFish.empty()){
                leftCount++;
            }
        }
    }
    
    
    int rightCount = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,Comp2> leftFish;
    for(int i=n-1;i>=0;i--){
        if(fish[i].second==0){
            leftFish.push(make_pair(i,fish[i].first));
        }else{
            while(!leftFish.empty() && fish[i].first > leftFish.top().second){
                leftFish.pop();
            }
            if(leftFish.empty()){
                rightCount++;
            }
        }
    }
    
    cout<<leftCount+rightCount;
    return 0;
}

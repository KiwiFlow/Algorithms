#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;
struct sort_pred {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.first >= right.first;
    }
};


int main(){
    int N;
    cin>>N;
    vector<pair<int,int> > data(N);
    for(int i=0;i<N;i++){
        int r,o;
        cin>>r>>o;
        data[i].first = r-o;
        data[i].second = r;
    }
    sort(data.begin(),data.end(),sort_pred());
    
    int add = 0;
    int space = 0;
    for(int i=0;i<N;i++){
    	
        if(space < data[i].second){
            add += (data[i].second-space);
            space = 0;
        }else{
            space -= data[i].second;
        }
        space += data[i].first;
        //cout<<data[i].first<<" "<<data[i].second<<" "<<space<<" "<<add<<endl;
    }
    cout<<add;
    return 0;
}

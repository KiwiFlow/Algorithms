#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int,int> > data(N);
    for(int i=0;i<N;i++) cin>>data[i].first>>data[i].second;
    sort(data.begin(),data.end());
    set<int> finishTime;
    finishTime.insert(data[0].second);
    int res = 1;
    for(int i=1;i<N;i++){
        if(data[i].first<*finishTime.begin()){
            res++;
        }else{
            set<int>::iterator up = upper_bound(finishTime.begin(),finishTime.end(),data[i].first);
            up--;
            finishTime.erase(up);
        }
        finishTime.insert(data[i].second);
    }
    cout<<res;
    return 0;
}

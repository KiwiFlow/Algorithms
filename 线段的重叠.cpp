#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<int,int> > data(N);
    for(int i=0;i<N;i++) cin>>data[i].first>>data[i].second;
    sort(data.begin(),data.end());
    int Max = data[0].second;
    int res = 0;
    for(int i=1;i<N;i++){
        res = max(res,min(Max,data[i].second)-data[i].first);
        Max = max(Max,data[i].second);
    }
    cout<<res;
    return 0;
}

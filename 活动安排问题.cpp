#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<pair<int,int> > data(N);
    for(int i=0;i<N;i++) cin>>data[i].second>>data[i].first;
    sort(data.begin(),data.end());
    int res = 1;
    int finish = data[0].first;
    for(int i=1;i<N;i++){
        if(data[i].second >= finish){
            res++;
            finish = data[i].first;
        }
    }
    cout<<res;
    return 0;
}

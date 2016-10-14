#include<iostream>
#include<vector>
using namespace std;

vector<pair<int,int> > v(100005);

void solve(vector<pair<int,int> > &v){
    v[0].first = 0,v[0].second = 0;
    v[1].first = 1,v[1].second = 1;
    for(int i=2;i<v.size();i++){
        if(i&1){
            v[i].first = v[i/2].first + v[i/2+1].first;
        }else{
            v[i].first = v[i/2].first;
        }
        v[i].second = max(v[i-1].second,v[i].first);
    }
}

int main(){
    int T;
    cin>>T;
    solve(v);
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        cout<<v[n].second<<endl;
    }
    return 0;
}

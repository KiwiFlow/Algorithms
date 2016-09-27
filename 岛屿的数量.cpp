#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct comp{
	bool operator() (const pair<int,int> &l,const pair<int,int> &r){
		return  l.first < r.first;
	}
};

int islands[50000]={0};
int visited[50000]={0};
int main(){
    int n,q;
    cin>>n>>q;
    vector<pair<int,int> > sea(n);
    for(int i=0;i<n;i++){
        cin>>sea[i].first;
        sea[i].second=i;
    }
    
    sort(sea.begin(),sea.end());
    //vector<int> islands(n,0);
    //vector<char> visited(n,0);
    islands[n-1] = 1;
    visited[sea[n-1].second] = 1;
    for(int i=n-2;i>0;i--){
        if(visited[sea[i].second+1]==1 && visited[sea[i].second-1]==1){
            islands[i] = islands[i+1]-1;
        }else{
        	if(visited[sea[i].second+1]==0 && visited[sea[i].second-1]==0){
        		islands[i] = islands[i+1]+1;
        	}else{
        		islands[i] = islands[i+1];
        	}
        }
        visited[sea[i].second] = 1;
    }
    islands[0] = 1;
    for(int i=0;i<q;i++){
        int water;
        cin>>water;
        vector<pair<int,int> >::iterator x = upper_bound(sea.begin(),sea.end(),make_pair(water,0),comp());
        if(x==sea.end()){
            cout<<0<<endl;
        }else{
            int d = (int)distance(sea.begin(),x);
            cout<<islands[d]<<endl;
        }
    }
    return 0;
}

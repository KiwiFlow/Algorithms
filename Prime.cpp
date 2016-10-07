#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
int cost[1000][1000];
int mincost[1000];
bool used[1000];
int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cost[i][j] = (i==j?0:INT_MAX);
        }
    }
    for(int i=0;i<e;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        a--;
        b--;
        cost[a][b]=c;
        cost[b][a]=c;
    }
    
    for(int i=0;i<v;i++){
        mincost[i] = INT_MAX;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;
    while(true){
        int ex = -1 ; // seleced point
        for(int u=0;u<v;u++){
            if(!used[u] && (ex==-1 || mincost[u]<mincost[ex])) ex = u;
        }
        
        if(ex==-1) break;
        used[ex] = true;
        res = res + mincost[ex];
        for(int u=0;u<v;u++){
            mincost[u] = min(mincost[u],cost[ex][u]);
        }
    }
    cout<<res;
    return 0;
}

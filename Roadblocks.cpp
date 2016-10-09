#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

typedef pair<int,int> P;

vector<P> G[5005];
int dist[5005];
int dist2[5005];

int main(){
	int n,r;
	cin>>n>>r;
	for(int i=0;i<r;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		a--;
		b--;
		G[a].push_back(P(b,c));
		G[b].push_back(P(a,c));
	}
	
	priority_queue<P,vector<P>,greater<P> > que;
	fill(dist,dist+n,INT_MAX);
	fill(dist2,dist2+n,INT_MAX);
	dist[0] = 0;
	que.push(P(0,0));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second, d = p.first;
		if (dist2[v] < d) continue;
		for(int i=0;i<G[v].size();i++){
			P e = G[v][i];
			int d2 = d + e.second;
			if(dist[e.first] > d2){
				swap(dist[e.first],d2);
				que.push(P(dist[e.first],e.first));
			}
			if(dist2[e.first] > d2 && dist[e.first] < d2){
				dist2[e.first] = d2;
				que.push(P(dist2[e.first],e.first));
			}
		}
	}
	cout<<dist2[n-1];
	return 0;
}

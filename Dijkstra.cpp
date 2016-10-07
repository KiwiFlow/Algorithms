#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

struct edge{
    int to,cost;
};

struct P{
	P(int a,int b,int c){
		first = a;
		second = b;
		sc = c;
	}
	int first;
	int second;
	int sc;
};

struct cmp{
     bool operator() (const P &a, const P &b)
     {
        if(a.first > b.first){
        	return true;
        }else{
        	if(a.first == b.first && a.sc < b.sc){
        		return true;
        	}else{
        		return false;
        	}
        }
     }
};


int score[500];

vector<edge> G[500];
int d[500];
int ss[500];

int main(){
	int n,m,start,end;
	cin>>n>>m>>start>>end;
	for(int i=0;i<n;i++){
		cin>>score[i];
	}
	for(int i=0;i<m;i++){
		edge tmp;
		int j;
		cin>>j>>tmp.to>>tmp.cost;
		G[j].push_back(tmp);;
	}
	priority_queue<P,vector<P>,cmp>que;
	
	fill(d,d+n,INT_MAX);
	fill(ss,ss+n,0);
	d[start] = 0;
	ss[start] = score[start];
	que.push(P(0,start,score[start]));
	
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		
		for(int i=0;i<G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v]+e.cost){
				d[e.to] = d[v] + e.cost;
				ss[e.to] = ss[v]+score[e.to];
				que.push(P(d[e.to],e.to,ss[v]+score[e.to]));
			}else{
				if(d[e.to] == d[v]+e.cost && ss[e.to] < ss[v]+score[e.to]){
					ss[e.to] = ss[v]+score[e.to];
					que.push(P(d[e.to],e.to,ss[v]+score[e.to]));
				}
			}
		}
	}

	
	cout<<d[end]<<" "<<ss[end];
    return 0;
}

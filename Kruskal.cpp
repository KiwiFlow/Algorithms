#include<iostream>
#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

struct edge{
    int u,v,cost;
};

/*Union Find Set*/
void init(int *par,int *rank,int n){
	for(int i=0;i<n;i++){
		par[i]=i;
		rank[i]=0;
	}
}

int find(int *par,int n,int x){
	if(x==par[x]) return x;
	else{
		return par[x] = find(par,n,par[x]);
	}
}

void unite(int *par,int *rank,int n,int x,int y){
	x = find(par,n,x);
	y = find(par,n,y);
	if(x==y) return;
	if(rank[x] < rank[y]){
		par[x] = y;
	}else{
		par[y] = x;
		if(rank[x]==rank[y]) rank[x]++;
	}
}

bool same(int *par,int n,int x,int y){
	return find(par,n,x) == find(par,n,y);
}

int par[1005];
int rankA[1005];
/*Union Find Set End*/

edge es[50005];

bool comp(const edge & e1,const edge &e2){
	return e1.cost < e2.cost;
}


int kruskal(int V,int E){
    sort(es,es+E,comp);
    init(par,rankA,V);
    int res = 0;
    for(int i=0;i<E;i++){
        if(!same(par,V,es[i].u,es[i].v)){
            unite(par,rankA,V,es[i].u,es[i].v);
            res += es[i].cost;
        }
    }
    return res;
}

int main(){
    int V,E;
    cin>>V>>E;
    for(int i=0;i<E;i++){
        scanf("%d %d %d",&es[i].u,&es[i].v,&es[i].cost);
    }
    cout<<kruskal(V,E);
    return 0;
}

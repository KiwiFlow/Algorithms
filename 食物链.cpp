#include<queue>
#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

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

int par[50005*3];
int rankA[50005*3];

int main(){
    int res = 0;
	int n,k;
	cin>>n>>k;
	int An = n*3;
	init(par,rankA,An);
	for(int i=0;i<k;i++){
		int d,x,y;
		scanf("%d %d %d",&d,&x,&y);
		x--;
		y--;
		if(d==1){
			if(x<0 || x>=n || y<0 || y>=n){
				res++;
			}else{
				if(same(par,An,x*3,y*3+1) || same(par,An,x*3,y*3+2) ||
				   same(par,An,x*3+1,y*3) || same(par,An,x*3+1,y*3+2) ||
				   same(par,An,x*3+2,y*3) || same(par,An,x*3+2,y*3+1)){
					   res++;
				   }else{
					   unite(par,rankA,An,x*3,y*3);
					   unite(par,rankA,An,x*3+1,y*3+1);
					   unite(par,rankA,An,x*3+2,y*3+2);
				   }
			}
		}else{
			if(x<0 || x>=n || y<0 || y>=n){
				res++;
			}else{
				if(same(par,An,x*3,y*3) || same(par,An,x*3,y*3+2) ||
				   same(par,An,x*3+1,y*3+1) || same(par,An,x*3+1,y*3) ||
				   same(par,An,x*3+2,y*3+2) || same(par,An,x*3+2,y*3+1)){
						res++;
				}else{
					unite(par,rankA,An,x*3,y*3+1);
					unite(par,rankA,An,x*3+1,y*3+2);
					unite(par,rankA,An,x*3+2,y*3);
				}
			}
		}
		//cout<<i<<" "<<res<<endl;
	}
    cout<<res;
    return 0;
}

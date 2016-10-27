#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int main(){
	int n,m;
	while(scanf("%d %d",&n,&m)==2){
		map<int,vector<int> > d;
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(!d.count(x)) d[x] = vector<int>();
			d[x].push_back(i);
		}
	    for(int i=0;i<m;i++){
			int k,v;
			scanf("%d %d",&k,&v);
			if(!d.count(v) || d[v].size()<k) printf("0\n");
			else printf("%d\n",d[v][k-1]);
		}
	}
	return 0;
}

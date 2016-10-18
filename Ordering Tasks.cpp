#include<cstdio>
#include<cstring>
const int maxn = 1000;
int n, m, G[maxn][maxn], c[maxn], topo[maxn], t;

void dfs(int u){
  for(int v = 0; v < n; v++){
	  if(G[u][v] && !c[v]) dfs(v);
  }
  c[u]=1;
  topo[t]=u;
  t--;
}

int main(){
  while(scanf("%d%d", &n, &m) == 2 && n) {
    memset(G, 0, sizeof(G));
	memset(c, 0, sizeof(c));
    for(int i = 0; i < m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
	  u--; v--;
      G[u][v] = 1;
    }
	t = n-1;
	for(int u = 0; u < n; u++) 
		if(!c[u]) dfs(u);
	for(int i=0;i<n;i++)
		printf("%d ",topo[i]);
	printf("\n");
  }
  return 0;
}

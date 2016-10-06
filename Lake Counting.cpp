#include<iostream>
using namespace std;

int n,m;
char a[100][100];

void dfs(int i,int j){
	a[i][j] = '.';
	for(int p=i-1;p<=i+1;p++){
		for(int q=j-1;q<=j+1;q++){
			if(p>=0 && p<n && q>=0 && q<m && !(p==i && q==j) && a[p][q]=='W'){
				dfs(p,q);	
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
		
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='W'){
				dfs(i,j);
				res++;
			}
		}
	}
	cout<<res;
	return 0;	
}

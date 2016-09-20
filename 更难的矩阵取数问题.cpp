#include<iostream>
#include<vector>
using namespace std;
int main(){
    int M,N;
    cin>>M>>N;
    vector<vector<int> > a(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++) cin>>a[i][j];
    }
    vector<vector<int> > pre(N,vector<int>(N,0));
    vector<vector<int> > cur(N,vector<int>(N,0));
    for(int step=0;step<M+N-1;step++){
        for(int x1=0;x1<N;x1++){
            for(int x2=x1;x2<N;x2++){
            	if(!(x1<=step && x1>step-M)) continue;
            	if(!(x2<=step && x2>step-M)) continue;
            	
                int maxNei = 0;
                maxNei = max(maxNei,pre[x1][x2]);
                if(x1>0){
                    maxNei = max(maxNei,pre[x1-1][x2]);
                    maxNei = max(maxNei,pre[x1-1][x2-1]);
                } 
                if(x2>0) maxNei = max(maxNei,pre[x1][x2-1]);
                cur[x1][x2] = maxNei + a[x1][step-x1] + (x1==x2?0:a[x2][step-x2]);
            }
        }
        for(int p=0;p<N;p++){
        	for(int q=0;q<N;q++) pre[p][q] = cur[p][q];
        }
    }
    cout<<cur[N-1][N-1];
    return 0;
}

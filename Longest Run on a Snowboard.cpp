#include<cstdio>
#include<vector>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int A[10000];
int s[105][105];

int d[10005] = {0};
vector<int> G[10005];
int dp(int i){
    if(d[i]) return d[i];
    d[i] = 1;
    for(int j=0;j<G[i].size();j++){
        d[i] = max(d[i],dp(G[i][j])+1);
    }
    return d[i];
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        /*clear*/
        memset(d,0,10005*sizeof(int));
        string place;
        cin>>place;
        int row,col;
        cin>>row>>col;
        for(int r = 0;r<row;r++){
            for(int c = 0;c<col;c++){
                scanf("%d",&s[r][c]);
            }
        }
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                G[r*col+c].clear();
                if(r-1>=0 && s[r-1][c]<s[r][c]){
                    G[r*col+c].push_back((r-1)*col+c);
                }
                if(r+1<row && s[r+1][c]<s[r][c]){
                    G[r*col+c].push_back((r+1)*col+c);
                }
                if(c-1>=0 && s[r][c-1]<s[r][c]){
                    G[r*col+c].push_back(r*col+c-1);
                }
                if(c+1<col && s[r][c+1]<s[r][c]){
                    G[r*col+c].push_back(r*col+c+1);
                }
                
            }
        }
       
        int ans = 0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                ans = max(ans,dp(r*col+c));
            }
        }
        cout<<place<<": "<<ans<<endl;
    }
    return 0;
}

#include<string>
#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;
struct P{
    int a,b,c;
    P(int x,int y,int z){
        a=x;
        b=y;
        c=z;
    }
};
void go(int x,int y,int z,int vis[][8],queue<P> & q){
    if(x>=0 && x<8 && y>=0 && y<8 && vis[x][y]==0){
        q.push(P(x,y,z+1));
    }
}

int main() {
    string s,e;
    int vis[8][8];
    while(cin>>s){
        cin>>e;
        int a = s[0]-'a',b = s[1]-'1';
        int c = e[0]-'a',d = e[1]-'1';
        memset(vis,0,8*8*sizeof(int));
        queue<P> q;
        q.push(P(a,b,0));
        vis[a][b]=1;
        while(!q.empty()){
            P t = q.front();
            q.pop();
            if(t.a == c && t.b == d){
                cout<<"To get from "<<s<<" to "<<e<<" takes "<<t.c<<" knight moves."<<endl;
                break;
            }else{
                go(t.a+2,t.b+1,t.c,vis,q);
                go(t.a+1,t.b+2,t.c,vis,q);
                go(t.a-2,t.b+1,t.c,vis,q);
                go(t.a-1,t.b+2,t.c,vis,q);
                go(t.a-2,t.b-1,t.c,vis,q);
                go(t.a-1,t.b-2,t.c,vis,q);
                go(t.a+1,t.b-2,t.c,vis,q);
                go(t.a+2,t.b-1,t.c,vis,q);
            }
        }
    }
    return 0;
}

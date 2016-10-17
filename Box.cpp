#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

pair<int,int> a[6];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    while(scanf("%d %d",&(a[0].first),&a[0].second)==2){
        if(a[0].first < a[0].second){
            swap(a[0].first,a[0].second);
        }
        for(int i=1;i<6;i++){
            scanf("%d %d",&a[i].first,&a[i].second);
            if(a[i].first < a[i].second){
                swap(a[i].first,a[i].second);
            }
        }
        sort(a,a+6);
        
        if(a[0]!=a[1] || a[2]!=a[3] || a[4]!=a[5]){
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        if(a[0].first == a[3].first){
            if((a[0].second == a[5].first && a[3].second == a[5].second) ||
               (a[0].second==a[5].second && a[3].second == a[5].first)){
                   cout<<"POSSIBLE"<<endl;
                   continue;
               }
        }
        
        if(a[0].first == a[3].second){
            if((a[0].second == a[5].first && a[3].first == a[5].second) ||
               (a[0].second==a[5].second && a[3].first == a[5].first)){
                   cout<<"POSSIBLE"<<endl;
                   continue;
               }
        }
        
        if(a[0].second == a[3].first){
            if((a[0].first == a[5].first && a[3].second == a[5].second) ||
               (a[0].first==a[5].second && a[3].second == a[5].first)){
                   cout<<"POSSIBLE"<<endl;
                   continue;
               }
        }
        
        if(a[0].second == a[3].second){
            if((a[0].first == a[5].first && a[3].first == a[5].second) ||
               (a[0].first==a[5].second && a[3].first == a[5].first)){
                   cout<<"POSSIBLE"<<endl;
                   continue;
               }
        }
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}

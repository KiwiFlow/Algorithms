#include<iostream>
using namespace std;
int ant[50001];
int main(){
    int N,L;
    cin>>N>>L;
    for(int i=0;i<N;i++) cin>>ant[i];
    int shortT=0,longT=0;
    for(int i=0;i<N;i++){
        shortT = max(shortT,min(ant[i],L-ant[i]));
        longT = max(longT,max(ant[i],L-ant[i]));
    }
    cout<<shortT<<" "<<longT;
    
    return 0;
}

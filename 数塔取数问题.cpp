#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<vector<int> > a(N,vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=N-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            a[i][j] += max(a[i+1][j],a[i+1][j+1]);
        }
    }
    cout<<a[0][0];
    return 0;
}

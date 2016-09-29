#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main(){
    string a;
    cin>>a;
    vector<vector<int> > d(a.size(),vector<int>(a.size(),0));
    for(int i=a.size()-2;i>=0;i--){
        for(int j=i+1;j<a.size();j++){
            if(a[i]==a[j]){
                d[i][j] = d[i+1][j-1];
            }else{
                d[i][j] = min(d[i+1][j],d[i][j-1])+1;
            }
        }
    }
    cout<<d[0][a.size()-1];
    return 0;
}

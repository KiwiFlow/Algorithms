#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    long long n;
    cin>>n;
    bool flag = false;
    for(long long i=(long long)sqrt(2*n);i>=2;i--){
        if( (2*n+i-i*i) % (2*i) == 0){
            cout<<(2*n+i-i*i) / (2*i)<<endl;
            flag = true;
        }
    }
    if(!flag){
        cout<<"No Solution";
    }
    return 0;
}

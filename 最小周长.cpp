#include<cmath>
#include<iostream>
using namespace std;
int main(){
    int s;
    cin>>s;
    int k = (int)sqrt(s);
    while(s%k){
        k--;
    }
    cout<<2*(k+s/k);
    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k;
    cin>>n>>k;
    int c;
    int charge = 0;
    for(int i=0;i<n;i++){
        cin>>c;
        if(i!=k){
            charge += c;
        }
    }
    int a;
    cin>>a;
    if(a==charge/2){
        cout<<"Bon Appetit";
    }else{
        cout<<a-charge/2;
    }
    return 0;
}

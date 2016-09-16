#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void reverse(vector<int> &a,int i,int j){
    while(i<j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,d;
    cin>>n>>d;
    vector<int> a(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

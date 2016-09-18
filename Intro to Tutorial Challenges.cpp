#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int V,n;
    cin>>V>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==V) cout<<i;
    }
    return 0;
}

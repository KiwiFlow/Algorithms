/*
TODO:
将sort替换成编程珠玑里的算法
*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &v:arr){
        cin>>v;
    }
    sort(arr.begin(),arr.end());
    for(auto &v:arr){
        cout<<v<<endl;
    }
    return 0;
}

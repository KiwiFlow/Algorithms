#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long T;
    cin>>T;
    long long a = T/2+T/3+T/5+T/7;
    long long b = T/6+T/10+T/14+T/15+T/21+T/35;
    long long c = T/30+T/42+T/70+T/105;
    long long d = T/210;
    cout<<T-(a-b+c-d);
    return 0;
}

#include<iostream>
using namespace std;
int main()
{
    int n,p;
    cin>>n>>p;
    long long ans=1;
    for(int i=1;i<=n;i++)
        ans=ans*i%p;
    cout<<ans;
    return 0;
}

#include<stdio.h>
#define N 50050
long long a[N];
int main()
{
    long long n,i,tem;
    a[0]=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&tem);
        a[i]=a[i-1]+tem;
    }
    long long Q;
    scanf("%lld",&Q);
    while(Q--)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        printf("%lld\n",a[s+t-1]-a[s-1]);

    }


}

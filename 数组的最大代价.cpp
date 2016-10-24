#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int b[50005];
int d_0[50005];
int d_1[50005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    d_0[1] = b[0]-1;
    d_1[1] = b[1]-1;
    for(int i=2;i<n;i++){
        d_0[i] = max(d_0[i-1],d_1[i-1]+b[i-1]-1);
        d_1[i] = max(d_0[i-1]+b[i]-1,d_1[i-1]+abs(b[i]-b[i-1]));
    }
    printf("%d",max(d_0[n-1],d_1[n-1]));
    return 0;
}

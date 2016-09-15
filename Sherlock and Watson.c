#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int N,K,Q;
    scanf("%d %d %d",&N,&K,&Q);
    K=K%N;
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    int x;
    for(int i=0;i<Q;i++){
        scanf("%d",&x);
        printf("%d\n",a[(x-K+N)%N]);
    }
    return 0;
}

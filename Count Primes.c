int countPrimes(int n) {
    if(n<=2){
        return 0;
    }
    char * acc = (char *)malloc(sizeof(char)*(n));
    memset(acc,1,sizeof(char)*(n));
    int ret = 0;
    for(int i=2;i<n;i++){
        if(acc[i]==1){
            //printf("%d ",i);
            for(int j=2*i;j<=n-1;j+=i){
                acc[j]=0;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(acc[i]==1){
            ret++;
        }
    }
    return ret;
}

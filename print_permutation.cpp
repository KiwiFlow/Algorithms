#include<cstdio>
int A[10000];
void print_permutation(int *A,int cur,int n){
    if(cur==n){
        for(int i=0;i<n;i++){
            printf("%d ",A[i]);
        }
        printf("\n");
    }else{
        for(int i=1;i<=n;i++){
            bool ok = true;
            for(int j=0;j<cur;j++){
                if(A[j]==i){
                    ok = false;
                    break;
                }
            }
            if(ok){
                A[cur] = i;
                print_permutation(A,cur+1,n);
            }
        }   
    }
}

int main() {
    int n;
    scanf("%d",&n);
    print_permutation(A,0,n);
    return 0;
}

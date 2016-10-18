#include<cstdio>
int a[50005];
int tmp[50005];
void inversion_number(int left,int right,int &ans){
    if(left == right) return;
    int mid = left + (right-left)/2;
    inversion_number(left,mid,ans);
    inversion_number(mid+1,right,ans);
    int i = left, j = mid+1;
    int k = 0;
    while(i<=mid && j<=right){
        if(a[j]>=a[i]){
            tmp[k] = a[i];
            k++;
            i++;
        }else{
            ans+=(mid-i+1);
            tmp[k] = a[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        tmp[k] = a[i];
        k++;
        i++;
    }
    while(j<=right){
        tmp[k] = a[j];
        k++;
        j++;
    }
    for(int t = left;t<=right;t++){
        a[t] = tmp[t-left];
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    inversion_number(0,n-1,ans);
    printf("%d",ans);
    return 0;
}

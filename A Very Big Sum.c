#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
    }
    long long s = 0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       s += arr[arr_i];
    }
    printf("%lld",s);
    return 0;
}

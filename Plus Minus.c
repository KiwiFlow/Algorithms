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
    int positive=0,negative=0,zero=0;
    for(int arr_i = 0; arr_i < n; arr_i++){
       if(arr[arr_i]>0){
           positive++;
        }else{
           if(arr[arr_i]<0){
               negative++;
           }else{
               zero++;
           }
       }
    }
    printf("%6f\n%6f\n%6f",(positive+0.0)/n,(negative+0.0)/n,(zero+0.0)/n);
    return 0;
}

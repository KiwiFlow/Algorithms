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
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          scanf("%d",&a[a_i][a_j]);
       }
    }
    int d1=0,d2=0;
    for(int a_i = 0; a_i < n; a_i++){
        d1+=a[a_i][a_i];
        d2+=a[a_i][n-1-a_i];
    }
    printf("%d",abs(d1-d2));
    return 0;
}

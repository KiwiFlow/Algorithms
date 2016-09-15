#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d",&a0,&a1,&a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d",&b0,&b1,&b2);
    int a_s = 0,b_s = 0;
    a_s = a_s + (a0>b0?1:0) + (a1>b1?1:0) + (a2>b2?1:0);
    b_s = b_s + (b0>a0?1:0) + (b1>a1?1:0) + (b2>a2?1:0);
    printf("%d %d",a_s,b_s);
    return 0;
}

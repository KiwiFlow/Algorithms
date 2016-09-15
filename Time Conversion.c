#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    int a = (time[0]-'0')*10+time[1]-'0';
    if(a==12){
        if(time[8]=='A'){
            time[0]=time[1]='0';
        }
    }else{
        if(time[8]=='P'){
            time[0]=(a+12)/10+'0';
            time[1]=(a+12)%10+'0';
        }
    }
    time[8]='\0';
    printf("%s",time);
    return 0;
}

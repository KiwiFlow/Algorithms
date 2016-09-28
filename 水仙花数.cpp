#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=n;1;i++){
        int bits = 0;
        int c=i;
        while(c){
            bits++;
            c/=10;
        }
        int b=i;
        int sum=0;
        while(b){
            sum+=(int)pow(b%10,bits);
            b/=10;
        }
        if(sum==i){
            cout<<sum;
            break;
        }
    }
    return 0;
}

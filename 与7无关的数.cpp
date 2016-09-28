#include<iostream>
#include<cmath>
using namespace std;
long long record[1000001]={0};
void init(){
    record[1]=1;
    for(long long i=2;i<1000001;i++){
        bool flag = true;
        if(i%7==0){
            flag = false;
        }
        long long b = i;
        while(b){
            if(b%10==7){
                flag = false;
                break;
            }
            b/=10;
        }
        record[i] = record[i-1]+(flag?i*i:0);
    }
}
int main(){
    init();
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
       int n;
       cin>>n;
       cout<<record[n]<<endl;
    }
    return 0;
}

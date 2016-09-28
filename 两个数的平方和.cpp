#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool flag = false;
    int left = 0,right = (int)sqrt(n);
    while(left<=right){
        if(left*left + right*right == n){
            cout<<left<<" "<<right<<endl;
            flag = true;
            left++;
        }else{
            if(left*left + right*right > n){
                right--;
            }else{
                left++;
            }
        }
    }
    if(!flag) cout<<"No Solution";
    return 0;
}

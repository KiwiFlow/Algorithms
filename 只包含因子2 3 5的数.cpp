#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define A 1000000000000000001
void init(vector<long long> &data){
	queue<long long> f_2,f_3,f_5;
    f_2.push(2);
    f_3.push(3);
    f_5.push(5);
    long long f;
    do{
        if(f_2.front()<f_3.front() && f_2.front()<f_5.front()){
            f = f_2.front();
            f_2.pop();
            f_2.push(2*f);
            f_3.push(3*f);
            f_5.push(5*f);
        }else{
            if(f_3.front()<f_2.front() && f_3.front()<f_5.front()){
                f = f_3.front();
                f_3.pop();
                f_3.push(3*f);
                f_5.push(5*f);
                
            }else{
                f = f_5.front();
                f_5.pop();
                f_5.push(5*f);
            }
        }
        data.push_back(f);
    }while(f<A);
}
int main(){
	vector<long long> data;
	init(data);
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        long long a;
        cin>>a;
        vector<long long>::iterator index = lower_bound(data.begin(),data.end(),a);
        cout<<*index<<endl;
    }
    return 0;
}

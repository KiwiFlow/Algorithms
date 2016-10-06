#include<iostream>
using namespace std;

int n;
int main(){
	while(true){
		cin>>n;
		if(n==0) break;
		if(n<3){
			cout<<"Alice"<<endl;
		}else{
			cout<<"Bob"<<endl;
		}
	}
	return 0;	
}

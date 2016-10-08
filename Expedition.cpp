#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct T{
	int f,s;
};
bool cmp(const T &a,const T &b){
	return a.f>b.f;
}

T a[10005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].f,&a[i].s);
	}
	sort(&a[0],&a[n],cmp);
	a[n].f = 0;
	a[n].s = 0;
	
	int L,P;
	cin>>L>>P;
	int res = 0;
	priority_queue<int> gas;
	for(int i=0;i<=n;i++){
		int dist = (i==0?(L-a[i].f):(a[i-1].f-a[i].f));
		while(!gas.empty() && dist > P){
			P+=gas.top();
			res++;
			gas.pop();
		}
		if(dist > P){
			cout<<-1;
			return 0;
		}
		gas.push(a[i].s);
		P -= dist;
	}
	cout<<res;
	return 0;
}

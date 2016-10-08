#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int a[1005];
int main(){
	while(1){
		int r,n;
		cin>>r>>n;
		if(r==-1 && n==-1) break;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		sort(a,a+n);
		int res = 0;
		int p=0,q=1;
		while(1){
			while(q<n && a[q]-r<=a[p]){
				q++;
			}
			int color = q-1;
			while(q<n && a[color]+r>=a[q]){
				q++;
			}
			res++;
			if(q==n) break;
			else{
				p=q;
				q++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

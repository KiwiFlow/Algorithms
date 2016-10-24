#include<vector>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<climits>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
typedef long long LL;
LL a[50005];
int main(){
	LL n;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	map<LL,int> tree;
	LL ans = INT_MAX;
	LL prefixSum = 0;
	for(int i=0;i<n;i++){
	    prefixSum+=a[i];
	    if(prefixSum>0) ans = min(ans,prefixSum);
	    if(!tree.empty()){
	        map<LL,int>::iterator it = tree.lower_bound(prefixSum);
	        if(it!=tree.begin()){
	            it--;
	            ans = min(ans,prefixSum-((*it).first));
	        }
	    }
	    tree[prefixSum]=0;
	}
	printf("%lld",ans);
	return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int a[1005];
struct triple{
	triple(int a,int b,int c):r(a),t(b),u(c) {}
	triple(){
		r=t=u=0;
	}
    int r,t,u;
};

bool cmp(const triple &a,const triple &b){
    return a.r < b.r;
}

struct cmp2{
    bool operator()(  const triple &t1, const triple &t2 ) const{
       return t1.r < t2.r;
   }
};
vector<triple> b(1000005);
int  main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int c = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            b[c].r=a[i]+a[j];
            b[c].t = i;
            b[c].u = j;
            c++;
        }
    }
    sort(&b[0],&b[c],cmp);
    bool flag = false;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            triple * low = lower_bound(&b[0],&b[c],triple(-(a[i]+a[j]),0,0),cmp2());
            triple * up = upper_bound(&b[0],&b[c],triple(-(a[i]+a[j]),0,0),cmp2());
            for(triple *p=low;p!=up;p++){
                if(p->t!=i && p->t!=j && p->u!=i && p->u!=j){
                    flag = true;
                    break;
                }
            }
        }
    }
    
    if(flag){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

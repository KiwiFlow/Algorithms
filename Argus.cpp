#include<cstdio>
#include<map>
#include<vector>
using namespace std;

struct Cmd{
	int q_num,period,order;
	bool operator <(const Cmd & right) const{
		return order>right.order || (order == right.order && q_num > right.q_num);
	}
};

int main(){
	priority_queue<Cmd> pq;
	char s[20];
	while(scanf("%s",s) && s[0]!='#'){
		Cmd c;
		scanf("%d %d",&c.q_num,&c.period);
		c.order = c.period;
		pq.push(c);
	}
	int k; scanf("%d",&k);
	for(int i;i<k;i++){
		Cmd c = pq.top(); pq.pop();
		printf("%d\n",c.q_num);
		c.order += c.period;
		pq.push(c);
	}
	return 0;
}

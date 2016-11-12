#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>

int m[10005], s[10005];
struct Item{
	double a; 
    int b, c; 
	Item(double h, int j, int p) :a(h), b(j), c(p) {}
};
struct cmp {
	bool operator() (const Item & a, const Item &b) {
		if (a.a == b.a) {
            if(a.b == b.b){
                return a.c < b.c;
            }else{
                return a.b < b.b;
            }
		}
		else {
			return a.a < b.a;
		}
	}
};
const int LIMIT = 10000;
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &m[i], &s[i]);
	std::priority_queue<Item,std::vector<Item>,cmp> pq;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (s[i] != s[j] && (m[i]-m[j])*(s[j]-s[i])>0) {
				double x = (m[i] - m[j])*1.0 / (s[j] - s[i]);
				if (x > 0) {
                    //printf("%d %d %d\n",x,i+1,j+1);
					pq.push(Item(x, s[i] > s[j] ? i : j, s[i] < s[j] ? i : j));
					if (pq.size() > LIMIT) {
						pq.pop();
					}
				}
			}
		}
	}
    //printf("size: %d\n",pq.size());
	if (pq.empty()) {
		printf("No Solution\n");
	}
	else {
		std::stack<std::pair<int, int> > sout;
		while (!pq.empty()) {
			sout.push(std::make_pair(pq.top().b, pq.top().c));
			pq.pop();
		}
		while (!sout.empty()) {
			printf("%d %d\n", sout.top().first+1, sout.top().second+1);
            sout.pop();
		}
	}
}

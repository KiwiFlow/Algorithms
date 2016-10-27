#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

struct Item {
	int s, b;
	Item(int s, int b) :s(s), b(b) {}
	bool operator < (const Item & right) const {
		return s > right.s;
	}
};

void merge(int *a, int *b, int *c, int n) {
	priority_queue<Item> pq;
	for (int i = 0; i < n; i++) {
		pq.push(Item(a[i] + b[0], 0));
	}
	for (int i = 0; i < n; i++) {
		Item e = pq.top(); pq.pop();
		c[i] = e.s;
		if (e.b + 1 < n) pq.push(Item(e.s - b[e.b] + b[e.b + 1], e.b + 1));
	}

}

int a[777], b[777];
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", i == 0 ? &a[j] : &b[j]);
			}
            if (i != 0){
                sort(b,b+n);
                merge(a, b, a,n);
            }else{
                sort(a,a+n);
            }
		}
		printf("%d", a[0]);
		for (int i = 1; i < n; i++) printf(" %d", a[i]);
		printf("\n");
	}
	return 0;
}

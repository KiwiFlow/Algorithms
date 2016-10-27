#include<iostream>
#include<set>
using namespace std;

void gen(set<int> & fibo) {
	int a = 1, b = 1;
	fibo.insert(1);
	while (a + b <= 100000000) {
		fibo.insert(a + b);
        int c = a+b;
		b = a;
		a = c;
	}
}
int main() {
	set<int> fibo;
	gen(fibo);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		if (fibo.count(n)) cout << "B" << endl;
		else cout << "A" << endl;
	}
	return 0;
}

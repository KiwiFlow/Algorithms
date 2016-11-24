#include<set>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
int getLen(int k) {
	int ret = 0;
	while (k != 1) {
		ret++;
		if (k & 1) {
			k = 3 * k + 1;
		}
		else {
			k = k / 2;
		}
	}
	return ret + 1;
}
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int i, j;
	while (scanf("%d%d", &i, &j) == 2) {
		int x = i, y = j;
		if (i > j) swap(i, j);
		int ans = 0;
		for (int k = i; k <= j; k++) {
			ans = max(ans, getLen(k));
		}
		printf("%d %d %d\n", x, y, ans);
	}
	return 0;
}

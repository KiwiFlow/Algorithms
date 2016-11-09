#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
typedef unsigned long long ULL;
ULL a[10005];
bool cmp(ULL a, ULL b) {
	ULL x = a, y = b;
	ULL ba = 0, bb = 0;
	while (x > 0) {
		ba++;
		x /= 10;
	}
	while (y > 0) {
		bb++;
		y /= 10;
	}
	return a*(ULL)pow(10, bb) + b < b*(ULL)pow(10, ba) + a;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, cmp);
	int count = 0;
	for (int i = 0; i < n; i++) {
		char str[20];
		sprintf(str, "%llu", a[i]);
		for (int j = 0; j < strlen(str); j++) {
			if (count == 1000) {
				printf("\n");
				count = 0;
			}
			printf("%c", str[j]);
			count++;
		}
	}
	return 0;
}

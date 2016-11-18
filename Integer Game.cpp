#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
using namespace std;

char d[1005];

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s", d);
		int count[3] = { 0,0,0 };
		int sum = 0;
		char *p = d;
		while (*p) {
			sum += (*p - '0');
			count[(*p - '0') % 3]++;
			p++;
		}
		if (sum % 3) {
			if (count[sum % 3]) {
				count[0]++;
			}
			else {
				printf("Case %d: T\n", i);
				continue;
			}
		}
		printf("Case %d: %c\n", i, (count[0] % 2) ? 'S' : 'T');
	}
	return 0;
}

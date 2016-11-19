#include<iostream>
#include<string>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<stdio.h>
#include<queue>
#include<climits>
#include<vector>
#include<map>
using namespace std;

struct node {
	int A, C, G, T;
	pair<char,int> getHamming() {
		char ans = 'A';
		char freq = A;
		int test[3] = { C,G,T };
		char ret[3] = { 'C','G','T' };
		for (int i = 0; i < 3; i++) {
			if (test[i] > freq) {
				ans = ret[i];
				freq = test[i];
			}
		}
		return make_pair(ans,freq);
	}
};

node da[1010];
char str[1010];
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		memset(da, 0, sizeof(da));
		memset(str, 0, sizeof(str));
		int m, n;
		scanf("%d%d", &m, &n);
		getchar();
		for (int k = 0; k < m; k++) {
			for (int j = 0; j < n; j++) {
				int x = getchar();
				switch (x) {
				case 'A': {
					++da[j].A;
					break;
				}
				case 'C': {
					++da[j].C;
					break;
				}
				case 'G': {
					++da[j].G;
					break;
				}
				case 'T': {
					++da[j].T;
					break;
				}
				default: {
					break;
				}
				}
			}
			getchar();
		}

		int dis = 0;
		for (int k = 0; k < n; k++) {
			pair<char, int> tmp = da[k].getHamming();
			str[k] = tmp.first;
			dis += (m - tmp.second);
		}
		printf("%s\n%d\n", str,dis);
	}
	return 0;
}

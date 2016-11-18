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

char a[105], b[105];
int main() {
	freopen("d:\\in.txt", "r", stdin);
	freopen("d:\\out.txt", "w", stdout);
	while (scanf("%s", a) != EOF) {
		scanf("%s", b);
		map<char, char> da, db;
		for (int i = 0; i < strlen(a); i++) {
			da[a[i]]++;
			db[b[i]]++;
		}
		bool ans = true;
		auto itb = db.begin();
		for (auto & val : da) {
			if (val.second != itb->second) {
				ans = false;
			}
			itb++;
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}

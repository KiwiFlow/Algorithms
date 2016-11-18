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
#include<algorithm>
using namespace std;

char a[105], b[105];
int da[26], db[26];
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	while (scanf("%s%s", a, b) == 2) {
		memset(da, 0, sizeof(da));
		memset(db, 0, sizeof(db));
		for (int i = 0; i < strlen(a); i++) {
			da[a[i]-'A']++;
			db[b[i]-'A']++;
		}
		sort(da, da + 26);
		sort(db, db + 26);
		bool ans = true;
		for (int i = 0; i < 26; i++) {
			if (da[i] != db[i]) {
				ans = false;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}

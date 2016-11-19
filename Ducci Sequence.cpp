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
#include<sstream>
#include<map>
using namespace std;
const int LIMIT = 1000;
int a[20];
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int t; scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n; scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[j]);
		}
		string ans = "LOOP";
		for (int j = 0; j < LIMIT; j++) {
			int sum = 0;
			int f = a[0];
			for (int k = 0; k < n - 1; k++) {
				a[k] = abs(a[k] - a[k + 1]);
				sum += a[k];
			}
			a[n - 1] = abs(a[n - 1] - f);
			sum += a[n - 1];
			if (sum == 0) {
				ans = "ZERO";
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

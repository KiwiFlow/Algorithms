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
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int m, n;
	while (scanf("%d%d", &m, &n) == 2) {
		printf("%d\n", m*n - 1);
	}
	return 0;
}

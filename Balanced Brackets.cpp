#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<cstdio>
#include<map>
#include<climits>
#include<algorithm>
#include<functional>
using namespace std;
const int NN = 50005;
int arr[NN];
const int MAX = 100000;
int stTableMin[MAX][32];
int stTableMax[MAX][32];
int preLog2[MAX];

void preLog_prepare(int n){
    preLog2[1] = 0;
	for (int i = 2; i <= n; i++) {
		preLog2[i] = preLog2[i - 1];
		if ((1 << preLog2[i] + 1) == i) {
			preLog2[i]++;
		}
	}
}

void st_prepare(int n, int *arr,int stTable[][32], int(*f)(int, int)){
	for (int i = n - 1; i >= 0; i--) { 
		stTable[i][0] = arr[i];
		for (int j = 1; (i + (1 << j) - 1) < n; j++) {
			stTable[i][j] = f(stTable[i][j - 1], stTable[i + (1 << j - 1)][j - 1]);
		}
    }
}

int maxF(int a, int b) {
	return max(a, b);
}
int minF(int a, int b) {
	return min(a, b);
}

int query(int L, int R, int stTable[][32],int (*f)(int,int)){
	int len = R - L + 1, k = preLog2[len];
	return f(stTable[L][k], stTable[R - (1 << k) + 1][k]);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
    preLog_prepare(n);
	st_prepare(n, arr, stTableMax, maxF);
	st_prepare(n, arr, stTableMin, minF);
	for (int i = 0; i < m; i++) {
		int L, R;
		scanf("%d%d", &L, &R);
		L--;
		R--;
		printf("%d\n", query(L, R, stTableMax, maxF) - query(L, R,stTableMin, minF));
	}
	return 0;
}









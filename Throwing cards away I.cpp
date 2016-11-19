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
#include<list>
using namespace std;
const int LIMIT = 1000;
int a[20];
int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n) && n) {
		list<int> card;
		for (int i = 1; i <= n; i++) {
			card.push_back(i);
		}
		printf("Discarded cards:");
		if (card.size() > 1) printf(" ");
		while (card.size() > 2) {
			int x = card.front();
			printf("%d, ", x);
			card.pop_front();
			int y = card.front();
			card.pop_front();
			card.push_back(y);
		}
		if (card.size() == 1) {
			printf("\nRemaining card: 1\n");
		}
		else {
			printf("%d", card.front());
			card.pop_front();
			printf("\nRemaining card: %d\n", card.front());
		}
	}
	return 0;
}

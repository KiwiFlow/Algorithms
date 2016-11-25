#include<stdio.h>
#include<string.h>
#include<math.h>
int d[3000];

int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int n;
	while (scanf("%d", &n)!=EOF) {
		memset(d, 0, sizeof(d));
		int cnt = 0;
		int pre, cur;
		for (int i = 0; i < n; i++) {
			scanf("%d", &cur);
			if (i && abs(cur-pre)>=0 && abs(cur - pre)<n && !d[(int)abs(cur - pre)]) {
				d[(int)abs(cur - pre)] = 1;
				cnt++;
			}
			pre = cur;
		}
		printf("%s\n", cnt == n - 1 ? "Jolly" : "Not jolly");
	}
	return 0;
}

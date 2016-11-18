#include<math.h>
#include<stdio.h>


int main() {
	//freopen("d:\\in.txt", "r", stdin);
	//freopen("d:\\out.txt", "w", stdout);
	int i = 1;
	int n;
	while (scanf("%d", &n) && n > 0) {
		printf("Case %d: %d\n", i++, (int)ceil(log2(n)));
	}
	return 0;
}

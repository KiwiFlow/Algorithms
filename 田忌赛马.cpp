#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int tianji[1005], qiwang[1005];
int main() {
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) scanf("%d", &tianji[i]);
		for (int i = 0; i < n; i++) scanf("%d", &qiwang[i]);
		sort(tianji, tianji + n);
		sort(qiwang, qiwang + n);
		int x = 0, y = 0, ans = 0;
		while (y < n) {
			if (tianji[y] > qiwang[x]) {
				ans += 200;
				x++;
			}
			else {
				if (tianji[y] == qiwang[x]) {
					x++;
				}
			}
			y++;
		}
		cout << ans - (n - x) * 200 << endl;
	}
	return 0;
}

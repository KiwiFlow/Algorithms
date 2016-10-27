#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <set>
#include<cstdio>

int main()
{
	int n;
	while (scanf("%d", &n) && n) {
		int ans=0;
		std::multiset<int> bag;
		for (int i = 0; i < n; i++) {
			int k; scanf("%d", &k);
			for (int j = 0; j < k; j++) {
				int x; scanf("%d", &x);
				bag.insert(x);
			}
			std::set<int>::iterator pmax = bag.end();
			pmax--;
            std::set<int>::iterator pmin = bag.begin();
			ans += (*pmax - *pmin);
            //std::cout<<*pmax<<" "<<*pmin<<std::endl;
            bag.erase(pmax);
            bag.erase(pmin);
            
		}
		printf("%d\n", ans);
	}
	return 0;
}

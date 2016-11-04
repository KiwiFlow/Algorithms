#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <ctime>;
#include <set>
#include <map>
using namespace std;
typedef long long ll;

#define INF 0x3fffffffffffffff

const ll mod = 1e9 + 7;
const int maxn = 1e7;

ll n1, n2;
ll dp[20];

void init()
{
	memset(dp, 0, sizeof(dp));
	ll i;
	for (i = 1; i <= 19; i++)
	{
		dp[i] = i*pow(10, i - 1);
	}
}

ll count(ll x,int nu)
{
	ll pre = 0;
	ll nx = x;
	ll result = 0;
	ll len = 0;
	ll digit = 0;
	ll radix = 1;
	ll tail = 0;
	while (x != 0)
	{
		digit = x % 10;
		x = x / 10;

		++len;

		if (digit > nu)
		{
			result += radix + digit*dp[len - 1];
		}
		else if (digit == nu)
		{
			result += tail + 1 + digit*dp[len - 1];  
		}
		else
		{
			result += digit*dp[len - 1];
		}

		tail = tail + digit*radix;
		radix *= 10;
	}
	if (nu == 0)
	{
		ll m = 1;
		while (nx != 0)
		{
			result -= m;
			m = m * 10;
			nx = nx / 10;
		}
	}
	return result;
}

int main()
{
	init();
	cin >> n1 >> n2;
	int i;
	for (i = 0; i <= 9; i++)
	{
		cout << count(n2, i) - count(n1 - 1, i) << endl;
	}
	return 0;
}

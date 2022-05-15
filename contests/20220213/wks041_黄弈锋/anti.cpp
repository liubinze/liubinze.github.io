#include<bits/stdc++.h>
using namespace std;
#define int long long

int T, n, k;
int mod;

int func(int n)
{
	int x = n & -n % mod;
	return (n + x) | ((n ^ (n + x)) / x) >> 2 % mod;
}

signed main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&k);
		mod = 1 << (k - 1);
		printf("%lld\n",func(n) % mod);
	}
	return 0;
}

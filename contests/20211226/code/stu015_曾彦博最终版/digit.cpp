#include <bits/stdc++.h>
using namespace std;

const long long M = 1e6;
long long l,r,dis[M + 5],f[M + 5];

long long check(long long x)
{
	long long res = 0;
	while(x > 0)
	{
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	long long t;
	scanf("%lld",&t);
	for(long long i = 1;i <= 9;i++) f[i] = i;
	for(long long i = 10;i <= M;i++) f[i] = f[check(i)];
	for(long long i = 1;i <= M;i++) dis[i] = dis[i - 1] + f[i];
	while(t--)
	{
		scanf("%lld %lld",&l,&r);
		if(r <= M) printf("%lld\n",dis[r] - dis[l - 1]);
		else if(r - l <= 1000)
		{
			long long ans = 0;
			for(long long i = l;i <= r;i++) ans += f[check(i)];
			printf("%lld\n",ans);
		}
	}
	return 0;
}

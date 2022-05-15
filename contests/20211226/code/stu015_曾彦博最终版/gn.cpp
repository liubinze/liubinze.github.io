#include <bits/stdc++.h>
using namespace std;

const long long M = 1e5;
long long prime_[M + 5],tot,dis[M + 5];
bool prime[M + 5];

void init()
{
	for(long long i = 2;i <= M;i++)
	{
		if(!prime[i]) prime_[++tot] = i;
		for(long long j = 1;j <= tot && i * prime_[j] <= M;j++)
		{
			prime[i * prime_[j]] = true;
			if(i % prime_[j] == 0) break;
		}
	}
}

int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	init();
	long long t;
	scanf("%lld",&t);
	for(long long i = 2;i <= M;i++)
	{
		long long tmp = i,idx = 1,res = 0;
		while(tmp > 1)
		{
			long long res_ = 0;
			while(tmp % prime_[idx] == 0)
			{
				tmp /= prime_[idx];
				res_++;
			}
			idx++;
			res = max(res,res_);
		}
		dis[i] = res;
	}
	while(t--)
	{
		long long n,ans = 0;
		scanf("%lld",&n);
		if(!prime[n])
		{
			printf("1\n");
			continue;
		}
		for(long long i = 1;i * i <= n;i++)
		{
			if(i * i == n) ans += i * dis[i];
			else if(n % i == 0)
			{
				ans += i * dis[n / i];
				ans += (n / i) * dis[i];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

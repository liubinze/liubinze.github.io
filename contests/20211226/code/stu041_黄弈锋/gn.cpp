#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t, n, tot;
ll p[10000005];
bool is[10000005];

ll f(ll a)
{
	if(a == 1) return 0;
	ll tmp = 0;
	ll cnt = 0;
	for(int i = 1; i <= tot; i++)
	{
		while(a % p[i] == 0) a /= p[i], tmp++;
		cnt = max(tmp, cnt);
		tmp = 0;
	}
	return cnt;
}


int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	scanf("%lld",&t);
	for (int i = 2; i <= 1e7; i ++)
	{
		if (!is[i]) p[++tot] = i;
		for (int j = 1; j <= tot && i * p[j] <= 1e7; j ++)
		{
			is[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	while(t--)
	{
		cin >> n;
		ll ans = 0;
		ll sn = sqrt(n);
		for(int i = 1; i <= sn; i++)
		{
			if(n % i == 0)
			{
				if(i * i == n) ans += i * f(i);
				else
				{
					ans += i * f(n / i) + (n / i) * f(i);
//					cout << f(n / i) << ' ' << f(i) << endl;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

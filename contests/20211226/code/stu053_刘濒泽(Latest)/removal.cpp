#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[1000001];
int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	ll n,m,x;
	while(scanf("%lld%lld%*d",&n,&m)>1)
	{
		for(ll i=0ll;i<n;i++)
			scanf("%lld",s+i);
		x=0ll;
		for(ll i=1ll;i<=m;i++)
			if(s[i]<s[x])
				x=i;
		printf("%lld",s[x]);
		for(ll i=1ll;i<n-m;i++)
		{
			for(ll j=++x;j<=m+i;j++)
				if(s[j]<s[x])
					x=j;
			printf(" %lld",s[x]);
		}
		puts("");
	}
	return 0;
}

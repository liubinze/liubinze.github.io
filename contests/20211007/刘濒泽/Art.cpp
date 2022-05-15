#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1001],dp[1001][1001];
int main()
{
	freopen("Art.in","r",stdin),freopen("Art.out","w",stdout);
	ll n,t,p;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	for(ll i=0ll;i<=n;i++)
		for(ll j=0ll;j<=n;j++)
			dp[i][j]=1e18;
	for(ll i=0ll;i<=n;i++)
		dp[i][1]=1ll;
	for(ll i=2ll;i<=n;i++)
		for(ll j=0ll;j<=n-i;j++)
		{
			for(ll k=1ll;k<i;k++)
				dp[j][i]=min(dp[j][i],dp[j][k]+dp[j+k][i-k]);
			if(e[j]==e[j+i-1])
			{
				for(ll k=1ll;k<i-1ll;k++)
					if(e[j+k]==e[j])
						dp[j][i]=min(dp[j][i],dp[j][k+1]+dp[j+k][i-k]-1ll);
				for(t=j;e[t]==e[j];t++);
				for(p=j+i-1ll;e[p-1]==e[j];p--);
				dp[j][i]=min(dp[j][i],dp[t][p-t]+1ll);
			}
		}
	printf("%lld",dp[0][n]);
	return 0;
}

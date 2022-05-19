#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[1000003],dp[1000001][9];
int main()
{
	freopen("plan.in","r",stdin),freopen("plan.out","w",stdout);
	ll m;
	scanf("%lld",&m);
	for(ll i=0ll;i<m;i++)
		scanf("%lld",v+i),dp[i][7]=-1e18;
	for(ll i=0ll;i<7ll;i++)
		dp[0][i]=v[0]*(i&1ll)+v[1]*(i>>1ll&1ll)+v[2]*(i>>2ll&1ll);
	for(ll i=1ll;i<=m;i++)
		for(ll j=0ll;j<7ll;j++)
			dp[i][j]=max(dp[i-1][j<<1&7],dp[i-1][j<<1&7|1])+v[i+2]*(j>>2ll&1ll);
	printf("%lld",dp[m][0]);
	return 0;
}

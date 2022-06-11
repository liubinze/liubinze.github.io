#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1001],dp[1001][1001];
int main()
{
	freopen("snakes.in","r",stdin),freopen("snakes.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=0ll,s=0ll,x=0ll;i<n;i++)
	{
		scanf("%lld",a+i),dp[i][0]=(i+1ll)*(x=max(x,a[i]))-(s+=a[i]);
		for(ll j=1ll;j<n;j++)
			dp[i][j]=1e18;
	}
	for(ll i=1ll;i<n;i++)
		for(ll j=1ll;j<i;j++)
			for(ll k=i-1ll,s=0ll,x=a[i];~k;k--)
				dp[i][j]=min(dp[i][j],dp[k][j-1]+(i-k)*(x=max(x,a[k+1]))-(s+=a[k+1]));
	printf("%lld",dp[n-1][k]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10001],dp[10001],e[10001],f[10001],lf=1ll,mAKe[5001][5001],le[10001],me[10001];
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	bool fk;
	ll n;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",a+i),dp[i]=1ll,e[i]=-1ll;
	for(ll i=n-2ll;~i;i--)
	{
		for(ll j=i+1ll;j<n;j++)
			if(a[i]<a[j]&&dp[j]>=dp[i])
				dp[i]=dp[j]+1ll,e[i]=j;
		for(ll j=i+1ll;j<n;j++)
			if(dp[i]==dp[j]+1ll&&a[j]>a[e[i]])
				e[i]=j;
	}
	for(ll i=1ll;i<n;i++)
		if(dp[f[0]]<dp[i])
			lf=0ll,f[lf++]=i;
		else if(dp[f[0]]==dp[i])
			f[lf++]=i;
	printf("%lld\n",dp[f[0]]);
	for(ll i=0ll,x=f[i];i<lf;x=f[++i])
		while(~x)
			mAKe[i][le[i]++]=a[x],x=e[x];
	for(ll i=0ll;i<lf;i++)
	{
		fk=0;
		for(ll j=0ll;j<le[i];j++)
			if(me[j]>mAKe[i][j])
				break;
			else if(me[j]<mAKe[i][j])
			{
				fk=1;
				break;
			}
		if(fk)
			for(ll j=0ll;j<le[i];j++)
				me[j]=mAKe[i][j];
	}
	for(ll i=0ll;i<dp[f[0]];i++)
		printf("%lld ",me[i]);
	return 0;
}

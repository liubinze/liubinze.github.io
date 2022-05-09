#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n;
int a[N],p[N],sum[N],f[N],b[N];

signed main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p[i],&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+(p[i]-p[i-1])*sum[i-1];
	}
	for(int i=n-1;i>=1;i--)
	{
		b[i]=b[i+1]+(p[i+1]-p[i])*(sum[n]-sum[i]);
	}
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		if(ans==-1)ans=f[i]+b[i];
		else ans=min(ans,f[i]+b[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

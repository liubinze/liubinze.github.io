#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001],b[1000001],f[1000001];
int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m),f[0]=1ll;
	for(ll i=0ll;i<=m;i++)
		scanf("%lld",b+i);
	for(ll i=0ll;i<n;i++)
	{
		for(ll j=0ll;j<=m;j++)
			if(b[j]>f[j])
			{
				a[i]=j;
				break;
			}
		for(ll j=m;j>=a[i];j--)
			f[j]+=f[j-a[i]];
		printf("%lld ",a[i]);
	}
	return 0;
}
#include<stdio.h>
typedef long long ll;
ll n,fa[1000001],ls[1000001],rs[1000001],siz[1000001],ans;
inline ll dfs(ll x)
{
	if(!~x)
		return 1ll;
	bool f=0;
	ll l=dfs(ls[x]),r=dfs(rs[x]);
	if(!~l||!~r)
		return -1ll;
	if(l<r)
		l^=r^=l^=r,ls[x]^=rs[x]^=ls[x]^=rs[x],ans++;
	for(ll i=0ll;i<20ll&&!f;i++)
		if(l==1ll<<i&&r>=l>>1ll||r==1ll<<i&&l<r<<1ll)
			f=1;
	if(!f)
		return -1ll;
	return siz[x]=l+r;
}
int main()
{
	scanf("%lld",&n);
	for(ll i=1ll;i<=n;i++)
	{
		scanf("%lld%lld",ls+i,rs+i);
		if(~ls[i])
			fa[ls[i]]=i;
		if(~rs[i])
			fa[rs[i]]=i;
	}
	if(~dfs(1ll))
		printf("%lld",ans);
	else
		printf("-1");
	return 0;
}

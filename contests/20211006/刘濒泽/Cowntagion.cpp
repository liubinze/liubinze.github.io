#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lastt[1000001],nextt[1000001],endd[1000001],fa[1000001],ans;
void dfs(ll x)
{
	ll t=0ll;
	for(ll i=lastt[x];i;i=nextt[i])
		if(endd[i]^fa[x])
			fa[endd[i]]=x,t++,dfs(endd[i]);
	ans+=ll(log2(t+1ll))+t;
	return;
}
int main()
{
	freopen("Cowntagion.in","r",stdin),freopen("Cowntagion.out","w",stdout);
	ll n,x,y;
	scanf("%lld",&n);
	for(ll i=1ll;i<n;i++)
		scanf("%lld%lld",&x,&y),
		nextt[i*2-1]=lastt[x],lastt[x]=i*2ll-1ll,endd[i*2-1]=y,
		nextt[i*2]=lastt[y],lastt[y]=i*2ll,endd[i*2]=x;
	dfs(1ll),printf("%lld",ans);
	return 0;
}

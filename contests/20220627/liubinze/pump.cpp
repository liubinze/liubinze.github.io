#include<stdio.h>
#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<time.h>
typedef long long ll;
bool vis[1000001],tl;
char s[1000001];
ll n,t,len,las[1000001],nex[1000001],en[1000001],c[1000001],f[1000001],ans=-1ll;
inline void addedg(ll x,ll y,ll _c,ll _f)
{
	nex[++len]=las[x],las[x]=len,en[len]=y,c[len]=_c,f[len]=_f;
	return;
}
inline void dfs(ll x,ll sc,ll mf)
{
	if((clock()-t)/CLOCKS_PER_SEC>0.9)
		return tl=1,void();
	if(sc&&mf*ll(1e6)/sc<=ans)
		return;
	if(x==n)
		return ans=mf*ll(1e6)/sc,void();
	vis[x]=1;
	for(ll i=las[x];i&&!tl;i=nex[i])
		if(!vis[en[i]])
			dfs(en[i],sc+c[i],mf<f[i]?mf:f[i]);
	vis[x]=0;
	return;
}
int main()
{
	freopen("pump.in","r",stdin),freopen("pump.out","w",stdout);
	ll m,a,b,c,f;
	scanf("%lld%lld",&n,&m);
	while(m--)
		scanf("%lld%lld%lld%lld",&a,&b,&c,&f),addedg(a,b,c,f),addedg(b,a,c,f);
	t=clock(),dfs(1ll,0ll,1e18),printf("%lld",ans);
	return 0;
}

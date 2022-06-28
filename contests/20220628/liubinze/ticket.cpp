#include<stdio.h>
using namespace std;
typedef long long ll;
const ll N=400001ll;
ll len,las[N],nex[N],en[N],c[N][3],fa[N][21],de[N],co[N],d[N],s[N],ans;
inline void addedg(ll a,ll b,ll c1,ll c2)
{
	nex[++len]=las[a],las[a]=len,en[len]=b,c[len][0]=c1,c[len][1]=c2;
	return;
}
inline void dfs(ll x)
{
	for(ll i=las[x];i;i=nex[i])
		if(en[i]^fa[x][0])
			fa[en[i]][0]=x,de[en[i]]=de[x]+1ll,co[en[i]]=i,dfs(en[i]);
	return;
}
inline void lca(ll x,ll y)
{
	if(x==y)
		return;
	if(de[x]<de[y])
		x^=y^=x^=y;
	d[x]--;
	if(de[x]>de[y])
	{
		for(ll i=20ll;~i;i--)
			if(de[fa[x][i]]>de[y])
				x=fa[x][i];
		if(fa[x][0]==y)
			return s[x]++,void();
		x=fa[x][0];
	}
	d[y]--;
	for(ll i=20ll;~i;i--)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],y=fa[y][i];
	s[x]++,s[y]++;
	return;
}
inline void sum(ll x)
{
	s[x]+=s[fa[x][0]]+d[fa[x][0]];
	for(ll i=las[x];i;i=nex[i])
		if(en[i]^fa[x][0])
			sum(en[i]);
	return;
}
int main()
{
	freopen("ticket.in","r",stdin),freopen("ticket.out","w",stdout);
	ll n,a,b,c1,c2;
	scanf("%lld",&n);
	for(ll i=1ll;i<n;i++)
		scanf("%lld%lld%lld%lld",&a,&b,&c1,&c2),addedg(a,b,c1,c2),addedg(b,a,c1,c2);
	dfs(1ll);
	for(ll i=0ll;i<20ll;i++)
		for(ll j=1ll;j<=n;j++)
			fa[j][i+1]=fa[fa[j][i]][i];
	for(ll i=1ll;i<n;i++)
		lca(i,i+1ll);
	sum(1ll);
	for(ll i=2ll;i<=n;i++)
		ans+=(c[co[i]][0]*s[i]<c[co[i]][1]?c[co[i]][0]*s[i]:c[co[i]][1]);
	printf("%lld",ans);
	return 0;
}

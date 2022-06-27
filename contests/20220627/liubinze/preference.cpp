#include<stdio.h>
typedef long long ll;
bool vis[300001];
char s[300001];
ll len,las[300001],nex[300001],en[300001],de[300001],fa[300001][21],ha[300001][21];
inline void addedg(ll x,ll y)
{
	nex[++len]=las[x],las[x]=len,en[len]=y;
	return;
}
inline void dfs(ll x)
{
	vis[x]=1;
	for(ll i=las[x];i;i=nex[i])
		if(!vis[en[i]])
			de[en[i]]=de[x]+1ll,fa[en[i]][0]=x,dfs(en[i]);
	return;
}
inline void init(ll n)
{
	for(ll i=0ll;i<20ll;i++)
		for(ll j=1ll;j<=n;j++)
			fa[j][i+1]=fa[fa[j][i]][i],ha[j][i+1]=ha[j][i]|ha[fa[j][i]][i];
	return;
}
inline bool lca(ll x,ll y,char c)
{
	ll ans=0ll;
	if(de[x]<de[y])
		x^=y^=x^=y;
	for(ll i=20ll;~i;i--)
		if(de[fa[x][i]]>=de[y])
			ans|=ha[x][i],x=fa[x][i];
	if(x==y)
		return (ans&ll(c))==ll(c);
	for(ll i=20ll;~i;i--)
		if(fa[x][i]^fa[y][i])
			ans|=ha[x][i]|ha[y][i],x=fa[x][i],y=fa[y][i];
	return ((ans|ha[fa[x][0]][0])&ll(c))==ll(c);
}
int main()
{
	freopen("preference.in","r",stdin),freopen("preference.out","w",stdout);
	ll n,m,x,y;
	scanf("%lld%lld%s",&n,&m,s+1);
	for(ll i=1ll;i<=n;i++)
		ha[i][0]=s[i];
	for(ll i=1ll;i<n;i++)
		scanf("%lld%lld",&x,&y),addedg(x,y),addedg(y,x);
	dfs(1ll),init(n);
	while(m--)
		scanf("%lld%lld%s",&x,&y,s),printf("%d",lca(x,y,s[0]));
	return 0;
}

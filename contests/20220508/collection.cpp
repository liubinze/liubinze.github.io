#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=3000001ll,mod=1e9+7,T=333333336ll;
bool mark[N];
ll n,V[N],u[N],v[N],len,las[N],nex[N],en[N],de[N],scc,le,e[N],link[N],dp[N];
queue<ll>q;
inline void addedg(ll x,ll y)
{
	nex[++len]=las[x],las[x]=len,de[en[len]=y]++;
	return;
}
inline void dfs(ll x)
{
	if(scc)
		link[x-n]=scc;
	mark[x]=1;
	for(ll i=las[x];i;i=nex[i])
		if(!mark[en[i]])
			dfs(en[i]);
	if(!scc)
		e[le++]=x+n;
	return;
}
int main()
{
	freopen("collection.in","r",stdin),freopen("collection.out","w",stdout);
	ll m,t,x,y,X,Y;
	scanf("%lld%lld%lld",&n,&m,&t);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",V+i);
	for(ll i=0ll;i<m;i++)
		scanf("%lld%lld",u+i,v+i),addedg(u[i],v[i]),addedg(u[i]+n,v[i]+n);
	for(ll i=1ll;i<=n;i++)
		if(!mark[i])
			dfs(i);
	for(ll i=0ll;i<le;i++)
		if(!mark[e[i]])
			scc++,dfs(e[i]);
	for(ll i=1ll;i<=n;i++)
		V[link[i]+n]+=V[i],dp[link[i]]+=V[i];
	for(ll i=0ll;i<m;i++)
		if(link[u[i]]^link[v[i]])
			addedg(link[v[i]]+n*2ll,link[u[i]]+n*2ll);
	for(ll i=1ll;i<=scc;i++)
		if(!de[i+n*2])
			q.push(i+n*2ll);
	while(!q.empty())
	{
		x=q.front(),q.pop();
		for(ll i=las[x];i;i=nex[i])
		{
			de[en[i]]--,dp[en[i]-n*2]=max(dp[en[i]-n*2],dp[x-n*2]+V[en[i]-n]);
			if(!de[en[i]])
				q.push(en[i]);
		}
	}
	while(t--)
		scanf("%lld%lld",&x,&y),printf("%lld %lld ",dp[link[x]]%mod,dp[link[y]]%mod),X=min(dp[link[x]],dp[link[y]]),Y=max(dp[link[x]],dp[link[y]]),printf("%lld\n",((Y-1ll)*Y%mod*(Y+1ll)%mod-(X-1ll)*X%mod*(X+1ll)%mod+mod)%mod*T%mod);
	return 0;
}

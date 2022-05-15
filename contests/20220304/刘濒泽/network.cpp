#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1000001ll;
bool vis[N],ins[N],in[N],ou[N];
ll len,las[N],nex[N],en[N],ti,dfn[N],low[N],scc,col[N],tmp,ans,bns=-1ll;
stack<ll>st;
inline void addedg(ll x,ll y)
{
	nex[++len]=las[x],las[x]=len,en[len]=y;
	return;
}
inline void tarjan(ll x)
{
	dfn[x]=low[x]=++ti,vis[x]=ins[x]=1,st.push(x);
	for(ll i=las[x];i;i=nex[i])
		if(!vis[en[i]])
			tarjan(en[i]),low[x]=min(low[x],low[en[i]]);
		else if(ins[en[i]])
			low[x]=min(low[x],dfn[en[i]]);
	if(dfn[x]==low[x])
	{
		++scc;
		do
			ins[tmp=st.top()]=0,col[tmp]=scc,st.pop();
		while(x^tmp);
	}
	return;
}
int main()
{
	freopen("network.in","r",stdin),freopen("network.out","w",stdout);
	ll n,x;
	scanf("%lld",&n);
	for(ll i=1ll;i<=n;i++)
		for(scanf("%lld",&x);x;scanf("%lld",&x))
			addedg(i,x);
	for(ll i=1ll;i<=n;i++)
		if(!vis[i])
			tarjan(i);
	for(ll i=1ll;i<=n;i++)
		for(ll j=las[i];j;j=nex[j])
			if(col[i]^col[en[j]])
				in[col[en[j]]]=1,ou[col[i]]=1;
	for(ll i=1ll;i<=scc;i++)
	{
		if(in[i])
			bns++;
		if(ou[i])
			ans++,bns++;
	}
	printf("%lld\n%lld",ans,bns);
	return 0;
}

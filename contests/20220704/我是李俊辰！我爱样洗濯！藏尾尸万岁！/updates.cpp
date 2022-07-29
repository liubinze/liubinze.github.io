#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool die[1000001],del[1000001];
ll e[1000001],len,las[1000001],nex[1000001],en[1000001],ti,mark[1000001],ans[1000001];
inline void addedg(ll x,ll y)
{
	nex[len]=las[x],las[x]=len,en[len++]=y;
	return;
}
inline void dfs(ll x)
{
	mark[x]=ti;
	for(ll i=las[x];~i;i=nex[i])
		if(!del[i>>1]&&mark[en[i]]<ti)
			dfs(en[i]);
	return;
}
int main()
{
	freopen("updates.in","r",stdin),freopen("updates.out","w",stdout);
	char s[11];
	ll n,q,x,y;
	scanf("%lld%lld",&n,&q),memset(las,-1,sizeof(las));
	for(ll i=0ll;i<q;i++)
	{
		scanf("%s",s),++ti;
		if(s[0]=='D')
			scanf("%lld",&x),die[x]=1;
		else if(s[0]=='A')
			scanf("%lld%lld",&x,&y),addedg(x,y),addedg(y,x);
		else
			scanf("%lld",&x),del[x-1]=1;
		for(ll j=1ll;j<=n;j++)
			if(!die[j]&&mark[j]<ti)
				dfs(j);
		for(ll j=1ll;j<=n;j++)
			if(!ans[j]&&mark[j]<ti)
				ans[j]=i;
	}
	for(ll i=1ll;i<=n;i++)
		printf("%lld\n",ans[i]?ans[i]:q);
	return 0;
}

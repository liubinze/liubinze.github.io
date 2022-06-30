#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[1000001],y[1000001],gc[1000001],a[1000001],ti,mark[1000001],ans;
vector<ll>v[1000001];
inline ll dfs(ll x)
{
	ll s=a[x];
	mark[x]=ti;
	for(ll i:v[x])
		if(mark[i]<ti)
			s+=dfs(i);
	return s;
}
int main()
{
	freopen("garbage.in","r",stdin),freopen("garbage.out","w",stdout);
	char s[11];
	bool f=0;
	ll n,m,q,t;
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1ll;i<=m;i++)
		scanf("%lld%lld",x+i,y+i),v[x[i]].push_back(y[i]),v[y[i]].push_back(x[i]);
	for(ll i=0ll;i<q;i++)
	{
		scanf("%s",s);
		if(s[0]^'G')
			scanf("%lld",gc+i);
	}
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",a+i);
	ti++,ans=t=dfs(1ll);
	for(ll i=0ll;i<q;i++)
		if(gc[i])
		{
			ans+=t,f=1;
			for(ll j=0ll;j<v[x[gc[i]]].size();j++)
				if(v[x[gc[i]]][j]==y[gc[i]])
					v[x[gc[i]]].erase(v[x[gc[i]]].begin()+j);
			for(ll j=0ll;j<v[y[gc[i]]].size();j++)
				if(v[y[gc[i]]][j]==x[gc[i]])
					v[y[gc[i]]].erase(v[y[gc[i]]].begin()+j);
		}
		else if(f)
			ti++,ans+=(t=dfs(1ll)),f=0;
		else
			ans+=t;
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[2][5000001];
ll len,las[5000001],nex[5000001],en[5000001],di[5000001],dis[2][5000001],le,e[5000001];
inline void addedg(ll x,ll y,ll z)
{
	nex[++len]=las[x],las[x]=len,en[len]=y,di[len]=z;
	return;
}
struct poi
{
	ll id,di;
};
inline bool operator<(poi a,poi b)
{
	return a.di>b.di;
}
priority_queue<poi>q;
inline void dijsktra(ll s,ll k)
{
	poi x;
	for(ll i=0ll;i<1000001ll;i++)
		dis[k][i]=1e17;
	dis[k][s]=0ll,q.push(poi{s,0ll});
	while(!q.empty())
	{
		x=q.top(),q.pop();
		if(mark[k][x.id])
			continue;
		mark[k][x.id]=1;
		for(ll i=las[x.id];i;i=nex[i])
			if(dis[k][en[i]]>x.di+di[i])
				dis[k][en[i]]=x.di+di[i],q.push(poi{en[i],dis[k][en[i]]});
	}
	return;
}
int main()
{
	freopen("portal.in","r",stdin),freopen("portal.out","w",stdout);
	ll n,m,t,s,x,_min=1e17;
	scanf("%lld%lld",&n,&m);
	for(ll i=1ll;i<=m;i++)
		for(scanf("%lld%lld",&t,&s);s--;)
			scanf("%lld",&x),addedg(x,n+i,t),addedg(n+i,x,0ll);
	dijsktra(1ll,0ll),dijsktra(n,1ll);
	for(ll i=1ll;i<=n;i++)
		if(max(dis[0][i],dis[1][i])<_min)
			_min=max(dis[0][i],dis[1][i]),e[(le=1)-1]=i;
		else if(max(dis[0][i],dis[1][i])==_min)
			e[le++]=i;
	if(_min==ll(1e17))
		return printf("-1"),0;
	printf("%lld\n",_min);
	for(ll i=0ll;i<le;i++)
		printf("%lld ",e[i]);
	return 0;
}

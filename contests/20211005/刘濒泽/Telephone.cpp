#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool s[1001][1001],mark[1000001];
ll n,b[1000001],dis[1000001];
struct cow
{
	ll id,s;
}_now,_next;
bool operator<(cow a,cow b)
{
	return a.s>b.s;
}
priority_queue<cow>pq;
int main()
{
	freopen("Telephone.in","r",stdin),freopen("Telephone.out","w",stdout);
	ll k;
	scanf("%lld%lld",&n,&k);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",b+i),b[i],dis[i]=1e18;
	for(ll i=1ll;i<=k;i++)
		for(ll j=1ll;j<=k;j++)
			scanf("%1d",&s[i][j]);
	dis[1]=0ll,pq.push(cow{1ll,0ll});
	while(!pq.empty())
	{
		_now=pq.top(),pq.pop();
		if(mark[_now.id])
			continue;
		mark[_now.id]=1;
		for(ll i=n;i;i--)
			if(s[b[_now.id]][b[i]]&&dis[i]>_now.s+abs(i-_now.id))
				dis[i]=_now.s+abs(i-_now.id),pq.push(cow{i,dis[i]});
	}
	printf("%lld",dis[n]);
	return 0;
}

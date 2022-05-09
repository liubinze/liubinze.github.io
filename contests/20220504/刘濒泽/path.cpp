#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[1000001];
ll len,las[1000001],nex[1000001],en[1000001],di[1000001],dis[1000001];
priority_queue<pair<ll,ll>>pq;
inline void addedg(ll x,ll y,ll z)
{
	nex[len]=las[x],las[x]=len,en[len]=y,di[len++]=z;
	return;
}
int main()
{
	freopen("path.in","r",stdin),freopen("path.out","w",stdout);
	ll n,m,q,x,y,z;
	scanf("%lld%lld%lld",&n,&m,&q),memset(las,-1,sizeof(las));
	while(m--)
		scanf("%lld%lld%lld",&x,&y,&z),addedg(x,y,z),addedg(y,x,z);
	while(q--)
	{
		scanf("%lld%lld",&x,&y),z=di[x-1<<1],di[x-1<<1]=di[x-1<<1|1]=y,mark[1]=0,pq.push(make_pair(0ll,1ll));
		for(ll i=2ll;i<=n;i++)
			dis[i]=1e18,mark[i]=0;
		while(!pq.empty())
		{
			y=pq.top().second,pq.pop();
			if(mark[y])
				continue;
			mark[y]=1;
			for(ll i=las[y];~i;i=nex[i])
				if(di[i]+dis[y]<dis[en[i]])
					dis[en[i]]=di[i]+dis[y],pq.push(make_pair(-dis[en[i]],en[i]));
		}
		printf("%lld\n",dis[n]),di[x-1<<1]=di[x-1<<1|1]=z;
	}
	return 0;
}

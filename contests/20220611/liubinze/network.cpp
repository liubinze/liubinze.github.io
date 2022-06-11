#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dad[1000001],x[1000001],y[1000001],xin[1000001],yin[1000001],xax[1000001],yax[1000001];
inline ll getdad(ll x)
{
	return dad[x]^x?dad[x]=getdad(dad[x]):x;
}
int main()
{
	freopen("network.in","r",stdin),freopen("network.out","w",stdout);
	ll n,m,ans=1e18;
	scanf("%lld%lld",&n,&m),iota(dad,dad+1000001,0);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld%lld",x+i,y+i);
	while(m--)
		scanf("%lld%lld",x,y),dad[getdad(x[0])]=getdad(y[0]);
	for(ll i=1ll;i<=n;i++)
		if(dad[i]==i)
			xin[i]=xax[i]=x[i],yin[i]=yax[i]=y[i];
	for(ll i=1ll,j;i<=n;i++)
		j=getdad(i),xin[j]=min(xin[j],x[i]),xax[j]=max(xax[j],x[i]),yin[j]=min(yin[j],y[i]),yax[j]=max(yax[j],y[i]);
	for(ll i=1ll;i<=n;i++)
		if(dad[i]==i)
			ans=min(ans,xax[i]-xin[i]+yax[i]-yin[i]<<1ll);
	printf("%lld",ans);
	return 0;
}

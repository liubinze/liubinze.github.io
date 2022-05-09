#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct f
{
	ll fr,to,di;
}e[5];
inline bool operator<(f a,f b)
{
	return a.di<b.di;
}
int main()
{
	freopen("distribution.in","r",stdin),freopen("distribution.out","w",stdout);
	ll t,d[5],ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld",d,d+1,d+2,d+3,&e[0].di,&e[1].di,&e[2].di,&e[3].di),ans=e[0].fr=e[1].fr=0ll,e[2].fr=e[3].fr=1ll,e[0].to=e[2].to=2ll,e[1].to=e[3].to=3ll,sort(e,e+4);
		for(ll i=0ll,j;i<4ll;i++)
			ans+=(j=min(d[e[i].fr],d[e[i].to]))*e[i].di,d[e[i].fr]-=j,d[e[i].to]-=j;
		printf("%lld\n",ans);
	}
	return 0;
}

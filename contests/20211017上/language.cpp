#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool b[1000001],andd[1000001],orr[1000001];
ll a[1000001],e[1000001];
int main()
{
	freopen("language.in","r",stdin),freopen("language.out","w",stdout);
	bool f;
	ll t,n,m,tot,tmp;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m),f=0,tot=0ll,tmp=-1ll;
		for(ll i=0ll;i<n;i++)
			scanf("%lld",a+i);
		for(ll i=0ll;i<=m;i++)
			andd[i]=1,orr[i]=0;
		for(ll i=0ll;i<n;i++)
			scanf("%d",b+i),andd[a[i]]&=b[i],orr[a[i]]|=b[i];
		for(ll i=0ll;i<=m;i++)
			if(andd[i]&&orr[i])
				tot++,tmp=i;
			else if(!andd[i]&&orr[i])
			{
				f=1;
				break;
			}
			else
				continue;
		if(f||tot>1ll)
			puts("^v^");
		else if(tot)
			printf("%lld\n",tmp);
		else
			puts(">-<");
	}
	return 0;
}

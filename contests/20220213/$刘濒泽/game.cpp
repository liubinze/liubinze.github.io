#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[1000001],m;
int main()
{
	freopen("game.in","r",stdin),freopen("game.out","w",stdout);
	ll t,n,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k),m=0ll;
		if((k&1ll)==0ll)
		{
			puts(k?"NO":"YES\n0");
			continue;
		}
		for(ll i=0ll;k;i++,m++)
			if(k>1ll<<i&&(k-(1ll<<i)&(1ll<<i+2ll)-1ll)||k==1ll<<i)
				ans[i]=k-(1ll<<i)+1ll,k-=1ll<<i;
			else if(k+(1ll<<i)<=n&&(k+(1ll<<i)&(1ll<<i+2ll)-1ll))
				ans[i]=k+1ll,k+=1ll<<i;
			else
				break;
		if(k)
			puts("NO");
		else
		{
			printf("YES\n%lld\n",m);
			for(ll i=0ll;i<m;i++)
				printf("%lld ",ans[i]);
			puts("");
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,x[10005];
bool u[10000005];
int main()
{
	freopen("frogs.in","r",stdin);
	freopen("frogs.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int a=1;a<=n;a++) scanf("%lld",&x[a]);
	for(int a=1;a<=n;a++)
	{
		if(__gcd(x[a],m)==1)
		{
			printf("%lld",m*(m+1)/2);
			return 0;
		}
		int tot=0;
		for(long long b=1;b<=m/__gcd(x[a],m)+1;b++)
		{
			tot=(tot+x[a])%m;
			u[tot]=1;
		}
	}
	for(long long a=1;a<=min(m,100000000ll);a++)
	{
		if(u[a]==1) ans+=(long long)a;
	}
	printf("%lld",ans);
}

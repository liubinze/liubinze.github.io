#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[2001][2001][3],cnt[2001][2001],lnk[2001];
int main()
{
	freopen("multiplication.in","r",stdin),freopen("multiplication.out","w",stdout);
	bool f;
	ll p;
	scanf("%lld",&p);
	for(ll i=0ll;i<p;i++)
		for(ll j=0ll;j<p;j++)
			scanf("%lld%lld",&e[i][j][1],&e[i][j][0]);
	for(ll i=0ll;i<p;i++)
		for(ll j=0ll;j<p;j++)
		{
			if(!cnt[i][e[i][j][1]])
				lnk[i]++;
			cnt[i][e[i][j][1]]++;
		}
	for(ll i=0ll;i<p;i++)
	{
		f=1;
		for(ll j=0ll;j<p;j++)
			if(e[i][j][0]^i||e[i][j][1]^i)
			{
				f=0;
				break;
			}
		if(f)
		{
			lnk[i]=0ll;
			break;
		}
	}
	for(ll i=0ll;i<p;i++)
		for(ll j=0ll;j<p;j++)
			if(lnk[i]*lnk[j]!=lnk[e[i][j][1]]*p+lnk[e[i][j][0]])
				return printf("F**k!"),0;
	printf("%lld",lnk[0]);
	for(ll i=1ll;i<p;i++)
		printf(" %lld",lnk[i]);
	return 0;
}

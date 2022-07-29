#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[3][1000003],link[3][1000001],g[3],p[1000003];
struct gam
{
	ll w,l,g;
}e[3];
int main()
{
	freopen("tenis.in","r",stdin),freopen("tenis.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=0ll;i<3ll;i++)
		for(ll j=1ll;j<=n;j++)
			scanf("%lld",&r[i][j]),link[i][r[i][j]]=j;
	for(ll i=2ll;i<=n;i++)
		for(ll j=1ll;j<i;j++)
		{
			for(ll k=0ll;k<3ll;k++)
				e[k]=gam{min(link[k][i],link[k][j]),max(link[k][i],link[k][j]),k};
			sort(e,e+3,[](gam a,gam b){return a.w<b.w||a.w==b.w&&(a.l<b.l||a.l==b.l&&a.g<b.g);}),g[e[0].g]++,p[e[0].w^link[e[0].g][i]?j:i]++;
		}
	for(ll i=0ll;i<3ll;i++)
		printf("%lld ",g[i]);
	puts("");
	for(ll i=1ll;i<=n;i++)
		printf("%lld ",p[i]);
	return 0;
}

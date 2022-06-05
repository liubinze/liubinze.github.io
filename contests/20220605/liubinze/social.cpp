#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
struct seg
{
	ll a,b;
}e[1000001];
inline bool cheat(ll d)
{
	ll t=e[0].a;
	for(ll i=1ll,j=0ll;i<n;i++)
	{
		while(j<m&&t+d>e[j].b)
			j++;
		if(j==m)
			return 0;
		t=max(t+d,e[j].a);
	}
	return 1;
}
int main()
{
	freopen("social.in","r",stdin),freopen("social.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=0ll;i<m;i++)
		scanf("%lld%lld",&e[i].a,&e[i].b);
	sort(e,e+m,[](seg x,seg y){return x.a<y.a;});
	ll l=1ll,r=e[m-1].b-e[0].a,mid;
	while(l<=r)
		if(cheat(mid=l+r>>1ll))
			l=mid+1ll;
		else
			r=mid-1ll;
	printf("%lld",r);
	return 0;
}

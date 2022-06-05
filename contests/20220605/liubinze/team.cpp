#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,b[1000001],las[1000001],pre[1000001],fir[1000001],nex[1000001];
int main()
{
	bool f=1;
	freopen("team.in","r",stdin),freopen("team.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1ll;i<=n;i++)
		las[i]=-1ll,fir[i]=n;
	for(ll i=0ll;i<n;i++)
		scanf("%lld",b+i),pre[i]=las[b[i]],las[b[i]]=i;
	for(ll i=1ll;i<=n;i++)
		if(las[i]==-1ll)
			f=0;
	if(f)
		return printf("%lld",n*(n-1ll)/2ll),0;
	for(ll i=n-1ll;~i;i--)
		nex[i]=fir[b[i]],fir[b[i]]=i;
	for(ll i=0ll;i<n;i++)
		for(ll j=pre[i]+1ll;j<i;j++)
			if(nex[j]>i)
				m++;
	printf("%lld",m);
	return 0;
}

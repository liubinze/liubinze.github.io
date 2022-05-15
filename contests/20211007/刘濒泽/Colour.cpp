#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001],g[1000001],h[1000001];
stack<ll>a,b;
int main()
{
	freopen("Colour.in","r",stdin),freopen("Colour.out","w",stdout);
	ll n,q,l,r;
	scanf("%lld%lld",&n,&q);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%lld",e+i),g[i]=(i?g[i-1]:0ll);
		while(!a.empty()&&e[a.top()]>e[i])
			g[i]++,a.pop();
		if(a.empty()||e[a.top()]<e[i])
			a.push(i);
	}
	g[n]=g[n-1]+a.size();
	for(ll i=n-1ll;~i;i--)
	{
		h[i+1]=h[i+2];
		while(!b.empty()&&e[b.top()]>e[i])
			h[i+1]++,b.pop();
		if(b.empty()||e[b.top()]<e[i])
			b.push(i);
	}
	h[0]=h[1]+b.size();
	while(q--)
		scanf("%lld%lld",&l,&r),printf("%lld\n",g[n]-g[l-1]-h[r]);
	return 0;
}

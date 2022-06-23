#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct cow
{
	ll w,t;
}e[1000001];
int main()
{
	freopen("show.in","r",stdin),freopen("show.out","w",stdout);
	ll n,w;
	scanf("%lld%lld",&n,&w);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].w,&e[i].t);
	sort(e,e+n,[](cow a,cow b){return a.w*b.t<a.t*b.w;});
	for(ll i=0ll,W=0ll,T=0ll;i<n;i++)
	{
		W+=e[i].w,T+=e[i].t;
		if(W>=w)
			return printf("%lld",T*1000ll/W),0;
	}
	return 0;
}

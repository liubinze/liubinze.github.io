#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001],b[1000001],le,ans;
struct f
{
	ll a,b;
}e[1000001];
inline void dfs(ll st,ll s,ll t)
{
	if(st==le)
		return ans=max(ans,s*t),void();
	return dfs(st+1ll,s+e[st].b,t),dfs(st+1ll,s,t*e[st].a);
}
int main()
{
	freopen("food.in","r",stdin),freopen("food.out","w",stdout);
	ll n,s=1ll;
	scanf("%lld",&n),srand(time(0));
	for(ll i=0ll;i<n;i++)
		scanf("%lld",a+i);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%lld",b+i);
		if(a[i]==1ll)
			s+=b[i];
		else
			e[le++]=f{a[i],b[i]};
	}
	dfs(0ll,s,1ll),printf("%lld",ans);
	return 0;
}

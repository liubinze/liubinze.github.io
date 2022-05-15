#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
#include<x86intrin.h>
using namespace std;
typedef long long ll;
const ll mod=998244353ll;
ll n,m,x,e[1001],s[1001],tot,ans;
map<ll,bool>mm;
int main()
{
	freopen("lantern.in","r",stdin),freopen("lantern.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&x);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%lld",e+i),s[i]=e[i]+(i?s[i-1]:0ll);
		if(!mm[e[i]])
			mm[e[i]]=1,tot++;
	}
	if(m>=tot)
	{
		for(ll i=0ll;i<n;i++)
			for(ll j=0ll;j<=i;j++)
				if(s[i]-(j?s[j-1]:0ll)>=x)
					ans++;
		printf("%lld",ans*2ll);
	}
	return 0;
}

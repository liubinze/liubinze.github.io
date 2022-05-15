#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("popcnt,tune=native")
#include<x86intrin.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1048577],mark[1048577],ans;
struct p
{
	ll f,s;
}_now;
vector<p>v[1048577];
int main()
{
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	ll n,x;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	for(_now.f=0ll;_now.f<n-1ll;_now.f++)
		for(_now.s=_now.f+1ll;_now.s<n;_now.s++)
			v[e[_now.f]^e[_now.s]].push_back(_now),mark[e[_now.f]^e[_now.s]]=1;
	for(ll i=0ll;i<n-1ll;i++)
		for(ll j=i+1ll;j<n;j++)
			if(mark[e[i]^e[j]])
			{
				x=v[e[i]^e[j]].size(),mark[e[i]^e[j]]=0;
				for(ll ii=0ll;ii<x;ii++)
					for(ll jj=0ll;jj<x;jj++)
						if(v[e[i]^e[j]][ii].f>v[e[i]^e[j]][jj].s)
							ans++;
			}
	printf("%lld",ans);
	return 0;
}

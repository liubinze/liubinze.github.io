#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001];
int main()
{
	freopen("tournament.in","r",stdin),freopen("tournament.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",e+i);
	sort(e,e+n);
	for(ll i=n-1ll;i;i--)
		if(e[i]-e[i-1]>k)
			return printf("%lld",n-i),0;
	printf("%lld",n);
	return 0;
}

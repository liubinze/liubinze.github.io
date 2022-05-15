#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("convex.in","r",stdin),freopen("convex.out","w",stdout);
	ll n,ans=0ll;
	scanf("%lld",&n);
	for(ll i=1ll;i<n-2ll;i++)
		ans+=i*(n-i-2ll);
	printf("%lld",ans*n/4ll);
	return 0;
}

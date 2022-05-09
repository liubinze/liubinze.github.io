#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000001],a[1000001];
int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	ll n,m,ans=0ll;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",p+i,a+i),i?a[i]+=a[i-1]:0ll;
	m=lower_bound(a,a+n,a[n-1]+1ll>>1ll)-a;
	for(ll i=0ll;i<n;i++)
		ans+=abs(p[m]-p[i])*(a[i]-(i?a[i-1]:0ll));
	printf("%lld",ans);
	return 0;
}

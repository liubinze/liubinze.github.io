#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e17;
ll n,k,c[10000001],f[10000001];
int main()
{
	freopen("var.in","r",stdin);
	freopen("var.out","w",stdout);
	ll s=0ll;
	scanf("%lld%lld",&n,&k);
	if(n<=k)
		return printf("0"),0;
	for(ll i=0ll;i<n;i++)
		scanf("%lld",c+i);
	sort(c,c+n);
	for(ll i=1ll;i<n;i++)
		f[i]=c[i]-c[i-1];
	sort(f+1,f+n);
	for(ll i=1ll;i<=n-k;i++)
		s+=f[i];
	printf("%lld",s);
	return 0;
}
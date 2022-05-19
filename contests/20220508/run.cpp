#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000001],b[1000001];
int main()
{
	freopen("run.in","r",stdin),freopen("run.out","w",stdout);
	ll x,y,n,m,_min=1e18;
	scanf("%lld%lld%lld%lld",&x,&y,&n,&m);
	if(x>y)
		x^=y^=x^=y;
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",a+i),a[i]+=a[i-1];
	for(ll i=1ll;i<=m;i++)
		scanf("%lld",b+i),b[i]+=b[i-1];
	for(ll i=n+1ll;i<=n+m;i++)
		a[i]=1e18;
	for(ll i=m+1ll;i<=n+m;i++)
		b[i]=1e18;
	for(ll i=0ll;i<=y-x;i++)
		_min=min(_min,max(a[i],b[y-x-i]));
	printf("%lld",_min);
	return 0;
}

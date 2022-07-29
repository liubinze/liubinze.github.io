#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100003];
int main()
{
	freopen("interesting.in","r",stdin),freopen("interesting.out","w",stdout);
	ll n,s;
	scanf("%lld%lld",&n,&s);
	for(ll i=1ll;i<=n;i++)
		scanf("%lld",a+i),a[i]+=a[i-1];
	for(ll i=1ll;i<=n;i++)
		for(ll k=n-i+1ll>>1ll;~k;k--)
			if(a[i+k-1]-a[i-1]<=s&&a[i+(k<<1)-1]-a[i+k-1]<=s)
			{
				printf("%lld\n",k<<1ll);
				break;
			}
	return 0;
}

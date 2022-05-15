#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
ll l,r;
ll res;
ll sm[10];
ll s(ll k)
{
	ll t=0;
	while (k)
	{
		t+=k%10;
		k/=10;
	}
	return t;
}
ll sf(ll x)
{
	if (x<10)
		return x;
	else
		sf(s(x));
}

int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	memset(sm,0,sizeof (sm));
	for (int i=1; i<=9; i++)
	{
		sm[i]=sm[i-1]+i;
	}
	scanf("%d",&q);
	while (q--)
	{
		res=0;
		scanf("%lld %lld",&l,&r);
		ll f1=sf(l);
		ll f2=sf(r);
		if (r-l==f2-f1)
		{
			res=sm[f2]-sm[f1-1];
			printf("%lld\n",res);
			continue;
		}
		ll ft,md,lt;
		ft=md=lt=0;
		ft=sm[9]-sm[f1-1];
		md=(r-(l+(9-f1)))/9LL*45LL;
		lt=sm[f2];
		res=ft+md+lt;
		printf("%lld\n",res);
	}
	return 0;
}
/*

*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int a[20];
ll func(ll n)
{
	ll x=n&(-n);
	return (n+x)|((n^(n+x))/x)>>2;
}

int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	a[1]=1,a[2]=2,a[3]=2,a[4]=4,a[5]=1,a[6]=3,a[7]=4,a[9]=1,a[10]=2,a[11]=2,a[13]=1;
	scanf("%d",&t);
	while(t--)
	{
		ll n,k;
		scanf("%lld%lld",&n,&k);
		if(a[n%16])printf("%lld\n",n+a[n%16]);
		else printf("%lld\n",func(n));
	}
	return 0;
}

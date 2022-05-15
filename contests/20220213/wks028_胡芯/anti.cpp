#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int t;
ll n;
ll res;
int k;
ll f()
{
	ll x=(n&(-n));
	return (n+x)|((n^(n+x))/x)>>2;
}
ll ksm(int n)
{
	ll res=1;
	ll a=2;
	while (n)
	{
		if (n&1)
		{
			res*=a;
		}
		a*=a;
		n>>=1;
	}
	return n;
}
int main()
{
	freopen("anti.in","r",stdin);
	freopen("anti.out","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		std::cin>>n>>k;
		if (n>ksm(k))
		{
			int u=64-k;
			n<<=u;
			n>>=u;
		}
		res=f();
		if (res>ksm(k))
		{
			int v=64-k;
			res<<=v;
			res>>=v;
		}
		std::cout<<res<<endl;
	}
	return 0;
}


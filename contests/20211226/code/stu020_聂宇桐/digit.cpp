#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q,f[105];
ll s(ll x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	scanf("%d",&q);
	for(ll i=1;i<=100;i++)
	{
		if(i<10)
		{
			f[i]=i;
		}
		else
		{
			f[i]=f[s(i)];
		}
	}	
	while(q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		ll ans=0;
		for(ll i=l;i<=r;i++)
		{
			ans+=f[s(i)];
		}
		cout<<ans<<endl;
	}
}

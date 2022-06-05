#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[1000001],st[1000001],t,s,ans;
int main()
{
	freopen("frisbees.in","r",stdin),freopen("frisbees.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
	{
		scanf("%lld",h+i);
		while(t&&h[st[t-1]]<h[i])
			ans+=i-st[--t]+1ll;
		if(t)
			ans+=i-st[t-1]+1ll;
		st[t++]=i;
	}
	printf("%lld",ans);
	return 0;
}

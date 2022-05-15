#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	ll q,l,r,x,ans;
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&l,&r),ans=(r-l)/9ll*45ll;
		for(ll i=l;i<=l+(r-l)%9ll;i++)
			ans+=(i-1ll)%9ll+1ll;
		printf("%lld\n",ans);
	}
	return 0;
}

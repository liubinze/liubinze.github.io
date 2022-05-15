#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll e[1000001];
int main()
{
	freopen("palindrome.in","r",stdin);
	freopen("palindrome.out","w",stdout);
	ll t,n,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n),a=b=0ll;
		for(ll i=0ll;i<n;i++)
			scanf("%lld",e+i),a+=(e[i]&1ll),b+=(e[i]>>1ll);
		if(a)
			printf("%lld\n",b/a*2ll+1ll);
		else
			printf("%lld\n",b*2ll);
	}
	return 0;
}
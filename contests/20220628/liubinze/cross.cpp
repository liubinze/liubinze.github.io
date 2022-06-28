#include<stdio.h>
using namespace std;
typedef long long ll;
ll s[1000001],t,ans;
int main()
{
	freopen("cross.in","r",stdin),freopen("cross.out","w",stdout);
	ll n,x;
	scanf("%lld",&n);
	while(n--)
	{
		scanf("%lld",&x);
		while(t&&s[t-1]>x)
			t--,ans++;
		if(!t||s[t-1]<x)
			s[t++]=x;
	}
	while(t&&s[t-1]>0ll)
		t--,ans++;
	printf("%lld",ans);
	return 0;
}

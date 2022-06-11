#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool sorted=0;
ll n,a[1000001],ans;
int main()
{
	freopen("bubblesort.in","r",stdin),freopen("bubblesort.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",a+i);
	while(!sorted)
	{
		sorted=1,ans++;
		for(ll i=1ll;i<n;i++)
			if(a[i]<a[i-1])
				a[i]^=a[i-1]^=a[i]^=a[i-1];
		for(ll i=n-1ll;i;i--)
			if(a[i]<a[i-1])
				a[i]^=a[i-1]^=a[i]^=a[i-1];
		for(ll i=1ll;i<n;i++)
			if(a[i]<a[i-1])
				sorted=0;
	}
	printf("%lld",ans);
	return 0;
}

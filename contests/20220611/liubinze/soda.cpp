#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[1000001];
int main()
{
	freopen("soda.in","r",stdin),freopen("soda.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",w+i);
	sort(w,w+n,[](ll a,ll b){return a>b;});
	for(ll i=0ll;i<n;i++)
		if(w[i+1]<=i)
			return printf("%lld",i+1ll),0;
	return 0;
}

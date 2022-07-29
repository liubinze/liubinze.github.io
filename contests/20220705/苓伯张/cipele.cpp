#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll le[3],e[3][1000001],d,ti,mark[1000001];
inline bool cheat(ll x)
{
	for(ll i=0ll,_;i<le[d];i++)
	{
		_=-1ll;
		for(ll j=lower_bound(e[d^1],e[d^1]+le[d^1],e[d][i]-x)-e[d^1],k=upper_bound(e[d^1],e[d^1]+le[d^1],e[d][i]+x)-e[d^1];j<k;j++)
			if(mark[j]<ti&&(!~_||abs(e[d^1][j]-e[d][i])>abs(e[d^1][_]-e[d][i])))
				_=j;
		if(~_)
			mark[_]=ti;
		else
			return 0;
	}
	return 1;
}
int main()
{
	freopen("cipele.in","r",stdin),freopen("cipele.out","w",stdout);
	scanf("%lld%lld",le,le+1);
	for(ll i=0ll;i<le[0];i++)
		scanf("%lld",&e[0][i]);
	for(ll i=0ll;i<le[1];i++)
		scanf("%lld",&e[1][i]);
	if(le[0]>le[1])
		d=1ll;
	sort(e[0],e[0]+le[0]),sort(e[1],e[1]+le[1]);
	ll l=0ll,r=max(abs(e[0][0]-e[1][le[1]-1]),abs(e[0][le[0]-1]-e[1][0])),mid;
	while(l<=r)
		if(++ti,cheat(mid=l+r>>1ll))
			r=mid-1ll;
		else
			l=mid+1ll;
	printf("%lld",l);
	return 0;
}

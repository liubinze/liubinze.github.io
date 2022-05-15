#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool e[2001][2001];
inline bool cheat(ll x,ll y)
{
	return e[x][y]&&(ll(x&&e[x-1][y])+ll(y&&e[x][y-1])+ll(e[x+1][y])+ll(e[x][y+1])==3ll);
}
int main()
{
	freopen("Comfortable1.in","r",stdin),freopen("Comfortable1.out","w",stdout);
	ll n,x,y,ans=0ll;
	scanf("%lld",&n);
	for(ll i=0ll,t;i<n;i++)
		scanf("%lld%lld",&x,&y),t=ll(x&&cheat(x-1ll,y))+ll(y&&cheat(x,y-1ll))+ll(cheat(x+1ll,y))+ll(cheat(x,y+1ll)),e[x][y]=1,
		printf("%lld\n",ans+=ll(x?cheat(x-1ll,y):0ll)+ll(y?cheat(x,y-1ll):0ll)+ll(cheat(x+1ll,y))+ll(cheat(x,y+1ll))+ll(cheat(x,y))-t);
	return 0;
}

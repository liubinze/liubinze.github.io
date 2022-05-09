#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1000001][11];
ll l[1000001],ans;
inline void f(ll x,ll y)
{
	bool fl=0;
	ll lin=min(l[x],l[y]),lax=max(l[x],l[y]);
	for(ll i=0ll;i<lin;i++)
		if(a[x][i]-'0'+a[y][i]-'0'+int(fl)>9)
			fl=1,ans++;
		else
			fl=0;
	for(ll i=lin;i<lax;i++)
		if(a[x][i]+a[y][i]-'0'+int(fl)>9)
			fl=1,ans++;
		else
			fl=0;
	return;
}
int main()
{
	freopen("carry.in","r",stdin),freopen("carry.out","w",stdout);
	ll n;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%s",a[i]),reverse(a[i],a[i]+(l[i]=strlen(a[i])));
	for(ll i=1ll;i<n;i++)
		for(ll j=0ll;j<i;j++)
			f(i,j);
	printf("%lld",ans);
	return 0;
}

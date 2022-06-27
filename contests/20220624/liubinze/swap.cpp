#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,cnt[1000001],lle,lri;
char s[1000001];
struct c
{
	char c;
	ll id,d;
}le[1000001],ri[1000001];
struct Fenwick
{
	ll c[1050001],n=1ll<<20ll;
	inline void add(ll x,ll d)
	{
		for(;x<=n;x+=x&-x)
			c[x]+=d;
		return;
	}
	inline ll sum(ll x)
	{
		ll s=0ll;
		for(;x;x^=x&-x)
			s+=c[x];
		return s;
	}
}F;
int main()
{
	freopen("swap.in","r",stdin),freopen("swap.out","w",stdout);
	scanf("%lld%s",&n,s);
	for(ll i=0ll;i<n<<1ll;i++)
		cnt[s[i]-'a']++;
	for(ll i=0ll;i<26ll;i++)
		cnt[i]>>=1ll;
	for(ll i=0ll;i<n<<1ll;i++)
		if(cnt[s[i]-'a'])
			cnt[s[i]-'a']--,ans+=i-lle,le[lle++]={s[i],lle,-1ll};
		else
			ri[lri++]={s[i],lri,-1ll};
	sort(le,le+lle,[](c a,c b){return a.c<b.c||a.c==b.c&&a.id<b.id;}),sort(ri,ri+lri,[](c a,c b){return a.c<b.c||a.c==b.c&&a.id<b.id;});
	for(ll i=0ll;i<n;i++)
		ri[i].d=le[i].id;
	sort(ri,ri+lri,[](c a,c b){return a.id<b.id;});
	for(ll i=n-1ll;~i;i--)
		ans+=F.sum(ri[i].d-1ll),F.add(ri[i].d,1ll);
	printf("%lld",ans);
	return 0;
}

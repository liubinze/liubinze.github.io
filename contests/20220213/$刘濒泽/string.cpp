#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000001],c[11];
ll link[1000001];
struct SegT
{
	struct node
	{
		ll l,r,cnt;
	}e[1000001];
	inline void build(ll num,ll l,ll r)
	{
		e[num].l=l,e[num].r=r,e[num].cnt=r-l+1ll;
		if(l<r)
			build(num<<1ll,l,l+r>>1ll),build(num<<1ll|1ll,l+r+2ll>>1ll,r);
		else
			link[l]=num;
		return;
	}
	inline ll del(ll num,ll l,ll r,char c)
	{
		if(e[num].l==e[num].r)
			return 1ll-(e[num].cnt-=ll(s[e[num].r]==c));
		ll t=e[num<<1].cnt,tt=e[num].cnt;
		if(l<=t)
			e[num].cnt-=del(num<<1ll,l,min(r,t),c);
		if(r>t)
			e[num].cnt-=del(num<<1ll|1ll,max(l-t,1ll),r-t,c);
		return tt-e[num].cnt;
	}
}st;
int main()
{
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	ll n,m,l,r,t;
	scanf("%lld%lld%s",&n,&m,s+1),st.build(1ll,1ll,t=n);
	while(m--)
	{
		scanf("%lld%lld%s",&l,&r,c);
		if(l>n)
			continue;
		n-=st.del(1ll,l,min(r,n),c[0]);
	}
	for(ll i=1ll;i<=t;i++)
		if(st.e[link[i]].cnt)
			printf("%c",s[i]);
	return 0;
}

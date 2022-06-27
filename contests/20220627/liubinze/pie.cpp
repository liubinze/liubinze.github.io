#include<stdio.h>
#include<algorithm>
typedef long long ll;
struct cow
{
	ll w,l,r;
}e[1000001];
int main()
{
	freopen("pie.in","r",stdin),freopen("pie.out","w",stdout);
	ll n,m,ans=0ll;
	scanf("%lld%lld",&n,&m);
	for(ll i=0ll;i<m;i++)
		scanf("%lld%lld%lld",&e[i].w,&e[i].l,&e[i].r);
	std::sort(e,e+m,[](cow x,cow y){return x.l<y.l||x.l==y.l&&x.r<y.r;});
	for(ll i=0ll,j,_;i<m;i++)
	{
		for(j=i+1ll,_=e[i].w;e[j].l=e[i].l&&e[j].r==e[i].r;j++)
			e[j].w>_?_=e[j].w:_;
		ans+=_,i=j-1ll;
	}
	printf("%lld",ans);
	return 0;
}

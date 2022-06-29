#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
bool mark[1000001];
ll a[1000001],link[1000001];
struct f
{
	ll n,id;
}e[1000001];
vector<ll>v[1000001];
struct SegT
{
	ll n=1ll<<20ll,mid[4200001];
	inline void init(ll n,ll l,ll r)
	{
		mid[n]=1e18;
		if(l+1ll<r)
			init(n<<1ll,l,l+r>>1ll),init(n<<1ll|1ll,l+r>>1ll,r);
		return;
	}
	inline void mod(ll n,ll l,ll r,ll x,ll y)
	{
		if(x<l||x>=r)
			return;
		if(x==l&&x+1ll==r)
			return mid[n]=y,void();
		if(x<l+r>>1ll)
			mod(n<<1ll,l,l+r>>1ll,x,y);
		else
			mod(n<<1ll|1ll,l+r>>1ll,r,x,y);
		mid[n]=min(mid[n<<1],mid[n<<1|1]);
		return;
	}
	inline ll _min(ll n,ll l,ll r,ll x,ll y)
	{
		if(y<=l||x>=r)
			return 1e18;
		if(x<=l&&y>=r)
			return mid[n];
		return min(_min(n<<1ll,l,l+r>>1ll,x,y),_min(n<<1ll|1ll,l+r>>1ll,r,x,y));
	}
}st;
int main()
{
	freopen("permutation.in","r",stdin),freopen("permutation.out","w",stdout);
	ll n,s=0ll;
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld",a+i),s+=a[i],e[i]=f{a[i],i};
	if(s<0ll)
		return printf("-1"),0;
	s=0ll;
	if(n<=1000ll)
	{
		for(ll i=0ll;i<n;i++)
			for(ll j=0ll;j<n;j++)
				if(!mark[j]&&s+a[j]>=0ll)
				{
					s+=a[j],mark[j]=1,printf("%lld ",j+1ll);
					break;
				}
		return 0;
	}
	sort(e,e+n,[](f x,f y){return x.n<y.n||x.n==y.n&&x.id<y.id;}),st.init(1ll,0ll,st.n);
	for(ll i=0ll;i<n;i++)
		link[e[i].id]=i,st.mod(1ll,0ll,st.n,i,e[i].id);
	for(ll i=0ll,j;i<n;i++)
		printf("%lld ",(j=st._min(1ll,0ll,st.n,lower_bound(e,e+n,f{-s,0ll},[](f x,f y){return x.n<y.n||x.n==y.n&&x.id<y.id;})-e,n))+1ll),st.mod(1ll,0ll,st.n,link[j],1e18),s+=a[j];
	return 0;
}

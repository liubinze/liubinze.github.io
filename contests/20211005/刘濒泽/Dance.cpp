#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[1000001];
ll e[1000001],a[1000001],b[1000001],lv,link[1000001],s[1000001];
vector<ll>v[1000001];
int main()
{
	freopen("Dance.in","r",stdin),freopen("Dance.out","w",stdout);
	ll n,k;
	scanf("%lld%lld",&n,&k);
	for(ll i=1ll;i<=n;i++)
		e[i]=i;
	for(ll i=0ll;i<k;i++)
		scanf("%lld%lld",a+i,b+i),swap(e[a[i]],e[b[i]]);
	for(ll i=1ll;i<=n;i++)
		if(!mark[i])
		{
			for(ll j=i;!mark[j];j=e[j])
				link[j]=lv,mark[j]=1;
			lv++;
		}
	for(ll i=1ll;i<=n;i++)
		e[i]=i,v[link[i]].push_back(i);
	for(ll i=0ll;i<k;i++)
		swap(e[a[i]],e[b[i]]),v[link[e[a[i]]]].push_back(a[i]),v[link[e[b[i]]]].push_back(b[i]);
	for(ll i=0ll;i<lv;i++)
	{
		sort(v[i].begin(),v[i].end()),unique(v[i].begin(),v[i].end()),s[i]=v[i].size();
		for(ll j=1ll;j<v[i].size();j++)
			if(v[i][j]<=v[i][j-1])
			{
				s[i]=j;
				break;
			}
	}
	for(ll i=1ll;i<=n;i++)
		printf("%lld\n",s[link[i]]);
	return 0;
}

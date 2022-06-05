#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[1000001];
ll n,m;
struct par
{
	ll x,y;
}e[1000001];
inline void dfs(ll d)
{
	mark[d]=1;
	for(ll i=0ll;i<n;i++)
		if(!mark[i]&&(e[i].x<=e[d].x&&e[i].y<=e[d].y||e[i].x>=e[d].x&&e[i].y>=e[d].y))
			dfs(i);
	return;
}
int main()
{
	bool f=1;
	freopen("particel.in","r",stdin),freopen("particel.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].x,&e[i].y);
	sort(e,e+n,[](par a,par b){return a.x<b.x;});
	for(ll i=1ll;i<n;i++)
		f&=e[i].y>e[i-1].y;
	if(f)
		return printf("%lld",n),0;
	for(ll i=0ll;i<n;i++)
		if(!mark[i])
			dfs(i),m++;
	printf("%lld",m);
	return 0;
}

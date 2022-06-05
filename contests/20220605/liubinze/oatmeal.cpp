#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[1000001];
ll n,m;
struct cow
{
	ll f,s;
}e[1000001];
int main()
{
	freopen("oatmeal.in","r",stdin),freopen("oatmeal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=0ll;i<n;i++)
		scanf("%lld%lld",&e[i].f,&e[i].s);
	for(ll i=0ll,s;i<n;i++)
	{
		s=0ll;
		for(ll j=1ll;j<=m;j++)
			mark[j]=1;
		for(ll j=i;j<n;j++)
			if(mark[e[j].f])
				mark[e[j].f]=0,s++;
			else if(mark[e[j].s])
				mark[e[j].s]=0,s++;
		printf("%lld\n",s);
	}
	return 0;
}

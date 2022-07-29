#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9;
char s[1000001];
ll w[1000001],lw,t[100001],lt;
inline void Plus(ll w[],ll&lw,ll t[],ll lt)
{
	for(ll i=0ll,j=max(lw,lt);i<j;i++)
		w[i]+=t[i];
	for(ll i=0ll;i<lw||w[i]>=M;i++)
		w[i+1]+=w[i]/M,w[i]%=M;
	while(w[lw]>0ll)
		lw++;
	return;
}
inline void Times(ll e[],ll&l,ll x)
{
	for(ll i=0ll;i<l;i++)
		e[i]*=x;
	for(ll i=0ll;i<l||e[i]>=M;i++)
		if(e[i]>=M)
			e[i+1]+=e[i]/M,e[i]%=M;
	while(e[l]>0ll)
		l++;
	return;
}
int main()
{
	freopen("setnja.in","r",stdin),freopen("setnja.out","w",stdout);
	scanf("%s",s),w[0]=lw=t[0]=lt=1ll;
	ll n=strlen(s);
	for(ll i=0ll;i<n;i++)
		if(s[i]=='L')
			Times(w,lw,2ll);
		else if(s[i]=='R')
			Times(w,lw,2ll),Plus(w,lw,t,lt);
		else
			Times(w,lw,5ll),Plus(w,lw,t,lt),Times(t,lt,3ll);
	printf("%lld",w[lw-1]);
	for(ll i=lw-2ll;~i;i--)
		printf("%09lld",w[i]);
	return 0;
}

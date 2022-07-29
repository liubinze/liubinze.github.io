#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool mark[1000001];
char c[1000001];
string s[1000001];
ll n,ans;
inline void dfs(ll st,ll x)
{
	bool f;
	ll t=s[x].length();
	mark[x]=1,ans=max(ans,st);
	for(ll i=0ll,j,_;i<n;i++)
		if(!mark[i]&&abs((j=s[i].length())-t)<2ll)
		{
			f=1;
			for(ll k=ll(j==t),l=min(j,t);k<l&&f;k++)
				if(s[i][k+j-l]^s[x][k+t-l])
					f=0;
			if(f)
				dfs(st+1ll,i);
		}
	return mark[x]=0,void();
}
int main()
{
	freopen("rima.in","r",stdin),freopen("rima.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=0ll;i<n;i++)
		scanf("%s",c),s[i]=c;
	for(ll i=0ll;i<n;i++)
		dfs(1ll,i);
	printf("%lld",ans);
	return 0;
}

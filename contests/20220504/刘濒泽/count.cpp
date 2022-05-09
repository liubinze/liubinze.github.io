#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bitset<5005>e[5005],b;
char s[1000001];
int main()
{
	freopen("count.in","r",stdin),freopen("count.out","w",stdout);
	ll n,ans=0ll;
	scanf("%lld",&n);
	for(ll i=0ll;i<n-1ll;i++)
	{
		scanf("%s",s);
		for(ll j=i+1ll;j<n;j++)
			e[i][j]=bool(s[j-i-1]-'0');
	}
	for(ll i=0ll;i<n-2ll;i++)
		for(ll j=i+1ll;j<n-1ll;j++)
		{
			b=(e[i][j]?e[i]&e[j]:e[i]|e[j]);
			for(ll k=j+1ll;k<n;k++)
				if(b[k]==e[i][j])
					ans++;
		}
	printf("%lld",ans);
	return 0;
}

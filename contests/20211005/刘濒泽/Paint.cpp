#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000003],qq[1000003],tp;
int main()
{
	freopen("Paint.in","r",stdin),freopen("Paint.out","w",stdout);
	ll n,q,a,b,ans;
	scanf("%lld%lld%s",&n,&q,s);
	while(q--)
	{
		scanf("%lld%lld",&a,&b),tp=ans=0ll;
		for(ll i=0ll;i<=n;i++)
			if(i<a-1ll||i>=b)
			{
				while(tp>0ll&&qq[tp-1]>s[i])
					tp--,ans++;
				if(!tp||qq[tp-1]^s[i])
					qq[tp++]=s[i];
			}
			else
			{
				while(tp>0ll&&qq[tp-1]>'\0')
					tp--,ans++;
				if(!tp||qq[tp-1])
					qq[tp++]='\0';
			}
		printf("%lld\n",ans);
	}
	return 0;
}

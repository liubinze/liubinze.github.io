#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[1000001];
int main()
{
	freopen("palindromic.in","r",stdin),freopen("palindromic.out","w",stdout);
	bool f;
	ll t,n,l,ans;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%s",s),n=strlen(s),l=ans=0ll;
		while(1)
		{
			f=0;
			for(ll i=1ll;i<=(n>>1ll)-l;i++)
			{
				f=1;
				for(ll j=0ll;j<i&&f;j++)
					if(s[j+l]^s[n-l-i+j])
						f=0;
				if(f)
				{
					l+=i,ans+=2ll;
					break;
				}
			}
			if(!f)
			{
				ans++;
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

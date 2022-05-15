#include<bits/stdc++.h>
using namespace std;
int f[205];
int dfs(int n)
{
	if(n<10)return n;
	else
	{
		int t=0;
		while(n>0)
		{
			t+=n%10;
			n/=10;
		}
		return dfs(t);
	}
}
int main()
{
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	int q;
	for(int i=1;i<=200;i++)
	{
		if(i<10)f[i]=i;
		else
		{
			int t=0;
			int k=i;
			while(k>0)
			{
				t+=k%10;
				k/=10;
			}
			f[i]=dfs(t);
		}
	}
	scanf("%d",&q);
	int tot=45;
	while(q--)
	{
		long long l,r;
		scanf("%lld%lld",&l,&r);
		int t=0;
		long long k=l,ans=0;
		while(k>0)
		{
			t+=k%10;
			k/=10;
		}
		ans+=tot;
		k=f[t]-1;
		while(k>0)ans-=k,k--;
		long long len=r-l-(9-f[t]+1)+1;
		ans+=(len/9)*tot;
		len%=9;
		for(int i=1;i<=len;i++)ans+=i;
		printf("%lld\n",ans);
	}
	return 0;
}

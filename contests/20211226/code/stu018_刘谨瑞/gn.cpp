#include<bits/stdc++.h>
using namespace std;
const int maxn=10000000;
int t,n,ans,p[1000000],pc,r[10000005],f[10000005];
bool isp[10000005];
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int i=2;i<=maxn;i++)
	{
		if(!isp[i])
		{
			p[++pc]=i;
			r[i]=1;
			f[i]=1;
		}
		for(int j=1;j<=pc&&i*p[j]<=maxn;j++)
		{
			isp[i*p[j]]=true;
			r[i*p[j]]=1;
			f[i*p[j]]=f[i];
			if(i%p[j]==0)
			{
				r[i*p[j]]=r[i]+1;
				f[i*p[j]]=max(f[i],r[i*p[j]]);
				break;
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=0;
		for(int i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				ans+=i*f[n/i];
				if(i*i!=n)
				{
					ans+=(n/i)*f[i];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

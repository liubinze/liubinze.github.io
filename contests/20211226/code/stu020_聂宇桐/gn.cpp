#include<bits/stdc++.h>
using namespace std;
long long t,p[10000000],cnt;
bool ip[10000005];
void nn()
{
	for(long long i=2;i<=10000000;i++)
	{
		if(!ip[i])
		{
			p[++cnt]=i;
		}
		for(long long j=1;j<=cnt&&i*p[j]<=10000000;j++)
		{
			ip[i*p[j]]=1;
			if(i%p[j]==0)
			{
				break;
			}
		}
	}
}
long long f(long long x)
{
	long long cn=0;
	for(long long i=1;i<=cnt&&x>1;i++)
	{
		long long k=0;
		while(x%p[i]==0)
		{
			x/=p[i];
			k++;
		}
		cn=max(cn,k);
	}
	return cn;
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	nn();
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%d",&n);
		if(ip[n]==0)
		{
			printf("1\n");
			continue;
		}
		long long ans=0;
		long long l=sqrt(n);
		for(long long j=1;j<=l;j++)
		{
			if(j*j==n)
			{
				ans+=n/j*f(j);
				continue;
			}
			if(n%j==0)
			{
				ans+=n/j*f(j);
				ans+=j*f(n/j);
			}
		}
		printf("%d\n",ans);
	}
}

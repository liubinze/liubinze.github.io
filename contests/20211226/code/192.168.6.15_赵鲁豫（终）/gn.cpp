#include<iostream>
#include<cmath>
using namespace std;
long long t,cnt,p[1000005],m[10000005],pp[10000005];
bool ip[10000005];
long long ppp(long long a)
{
	if(pp[a]!=0)
		return pp[a];
	long long pk=0,r=0,mr=0;
	while(a>1)
	{
		if(m[a]!=pk)
		{
			mr=max(r,mr);
			pk=m[a];
			r=1;
		}
		else
		{
			r++;
		}
		a=a/m[a];
	}
	pp[a]=max(r,mr);
	return pp[a];
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=2;i<=10000000;i++)
	{
		if(!ip[i])
		{
			p[++cnt]=i;
			m[i]=i;
		}
		for(long long j=1;j<=cnt&&i*p[j]<=10000000;j++)
		{
			ip[i*p[j]]=1;
			m[i*p[j]]=p[j];
			if(i%p[j]==0)
				break;
		}
	}
	while(t--)
	{
		long long n,ans=0,t;
		scanf("%lld",&n);
		if(!ip[n])
		{
			printf("1\n");
			continue;
		}
		t=sqrt(n);
		for(long long i=1;i<=t;i++)
			if(n%i==0)
			{
				ans+=i*ppp(n/i);
				if(i*i!=n)
					ans+=n/i*ppp(i);
			}
		printf("%lld\n",ans);
	}
}


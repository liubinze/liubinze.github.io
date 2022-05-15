#include<bits/stdc++.h>
using namespace std;
const long long N=1000001;
long long cao[10000001],prime[10000001],min_p[10000001],C,max_r[10000001],ans=0;
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);	
	for(int i=2;i<=N;i++)
	{
		if(cao[i]==0)
		{
			
			min_p[i]=i;
			prime[C]=i;
			C++;
			for(int j=2;j*i<=N;j++)
			{
				if(cao[j*i]==1)
				continue;
				cao[j*i]=1;
				min_p[i*j]=i;
			}
		}
	}
	max_r[1]=0;
	for(int i=2;i<=N;i++)
	{
		int p=i,last=min_p[i],max_=0,shu=0;
		while(p>1)
		{
			if(min_p[p]!=last)
			{
			shu=0;
			last=min_p[p];	
			}
			shu++;
			max_=max(max_,shu);
			p/=min_p[p];
		}
		max_r[i]=max_;
	}
	long long q;
	scanf("%lld",&q);
	while(q>0)
	{
		q--;
		long long l;
		scanf("%lld",&l);
		ans=0;
		for(long long i=1;i<sqrt(l);i++)
		{
			if(l%i==0)
			{
				ans+=(l/i)*max_r[i];	
				ans+=i*max_r[l/i];
			}
		}
		int j=sqrt(l);
		if(j*j!=l)
		{
		}
		else
		ans+=j*max_r[j];
		printf("%lld\n",ans);
	}
}

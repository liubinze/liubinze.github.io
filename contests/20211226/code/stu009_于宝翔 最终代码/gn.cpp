#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e7+5,M=1e5+5;

bool is_prime[N];
int idx,t,n,k,m;
int prime[N],minp[N],f[M],p[M],r[M],maxr[N];
ll ans;

void init()
{
	for(int i=2;i<N;i++)
	{
		if(!is_prime[i])prime[++idx]=i,minp[i]=i;
		for(int j=1;j<=idx&&i*prime[j]<N;j++)
		{
			is_prime[i*prime[j]]=true,minp[i*prime[j]]=prime[j];
			if(i%prime[j]==0)break;
		}
	}
}

int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	init();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int t=n;
		k=0;
		while(t>1)
		{
			p[++k]=minp[t],r[k]=0;
			while(t%p[k]==0)
			{
				r[k]++,t/=p[k];
			}
		}
		m=0;
		f[++m]=1;
		for(int i=1;i<=k;i++)
		{
			int range=m,pk=1;
			for(int j=1;j<=r[i];j++)
			{
				pk*=p[i];
				for(int j=1;j<=range;j++)
				{
					f[++m]=pk*f[j];
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			int p,r,temp=f[i];
			if(f[i]==1){maxr[i]=0;continue;}
			maxr[f[i]]=0;
			while(temp>1)
			{
				p=minp[temp],r=0;
				while(temp%p==0)
				{
					temp/=p;
					r++;
				}
				maxr[f[i]]=max(maxr[f[i]],r);
			}
		}
		ans=0;
		for(int i=1;i<=m;i++)
		{
			ans+=1ll*f[i]*maxr[n/f[i]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,m,prime[1000005],z[10000005],p[1000005],g[1000005],ans;
bool isprime[10000005];
void search(int h,int sum,int cnt)
{
	if(h>m)
	{
		ans+=n/sum*cnt;
		return;
	}
	for(int a=1,b=0;b<=g[h];a*=p[h],b++) search(h+1,sum*a,max(cnt,b));
}
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	for(int a=2;a<=1e7;a++)
	{
		if(isprime[a]==0) prime[++m]=a,z[a]=a;
		for(int b=1;b<=m&&a*prime[b]<=1e7;b++)
		{
			isprime[a*prime[b]]=1;
			z[a*prime[b]]=prime[b];
			if(a%prime[b]==0) break;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int h=n;
		m=0;
		ans=0;
		while(h>1)
		{
			if(z[h]!=p[m]) p[++m]=z[h],g[m]=1;
			else g[m]++;
			h/=z[h];
		}
		search(1,1,0);
		printf("%d\n",ans);
	}
}

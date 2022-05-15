#include<bits/stdc++.h>
#define int long long
using namespace std;
int fac[10000001],ci[10000001];
void find(int n,int k)
{
	bool flag=0;
	int cnt;
	for(int i=1; ;i++)
	{
		if(1+fac[i]>k)
		{
			flag=1;
			printf("NO\n");
			break;
		}
		if(1+fac[i]==k)
		{
			cnt=i;
			printf("YES\n");
			break;
		}
	}
	if(!flag)
	{
		if(k==1)printf("1\n"),printf("1\n");
		if(k==3)
		{
			printf("2\n");
			printf("1 2\n");
		}
		else 
		{
			printf("%lld\n",ci[cnt]+1);
			for(int i=2;i<=ci[cnt];i++)printf("%lld ",i);
			printf("1 2\n");
		}
	}
}
int t,n,k;
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&t);
	fac[0]=1;
	for(int i=1;i<=log2(1000000000);i++)fac[i]=2*fac[i-1],ci[i]=ci[i-1]+1;
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		if(k==0)
		{
			printf("YES\n");
			printf("0\n");
			continue;
		}
		if(n==1)
		{
			printf("YES\n");
			printf("0\n");
			continue;
		}
		if(n==2)
		{
			if(k==1)
			{
				printf("YES\n");
				printf("1\n");
				printf("1\n");
				continue;
			}
			if(k==0)
			{
				printf("YES\n");
				printf("0\n");
				continue;
			}
			else
			{
				printf("NO\n");
				continue;
			}
		}
		find(n,k);
	}
}

#include<bits/stdc++.h>
using namespace std;
long long po[100];
void init()
{
	for(long long i=0;i<=31;i++)
	{
		po[i]=pow(2,i);
	}
}
bool pd(long long x)
{
	long long sum=0;
	for(long long i=0;i<=31;i++)
	{
		sum+=po[i];
		if(sum==x)return true;
	}
	return false;
}
long long t;
int main()
{
	init();
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long n,k,l=0;
		scanf("%lld%lld",&n,&k);
		if(k==0)
		{
			printf("YES\n0\n");
			continue;
		}
		if(pd(k))
		{
			long long sum=0;
			for(long long i=0;i<=31;i++)
			{
				sum+=po[i];
				if(sum==k)
				{
					l=i+1;
					break;
				}
			}
			printf("YES\n%lld\n",l);
			sum=1;
			for(long long i=0;i<l;i++)
			{
				printf("%d ",sum);
				sum+=po[i];
			}
			printf("\n");
			continue;
		}
		else
		{
			printf("NO\n");
		}
	}
}


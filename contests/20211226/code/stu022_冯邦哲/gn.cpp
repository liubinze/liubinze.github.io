#include<bits/stdc++.h>
using namespace std;
int sum[9000000],cnt,n,t,a[1000001];
bool flag[100000001];
int main()
{
	freopen("gn.in","r",stdin);
	freopen("gn.out","w",stdout);
	flag[0]=flag[1]=1;
	for(int i=2;i<=20000000;i++)
	{
		if(flag[i]==0)
		{
			sum[++cnt]=i;
			a[i]=1;
		}
		for(int j=1;j<=cnt&&i*sum[j]<=20000000;j++)
		{
			flag[i*sum[j]]=1;
			a[i*sum[j]]=sum[j];
			if(i*sum[j]==0)
			{
				cout<<"odspo"<<endl;
				break;
			}
		}
	}
	for(int i=1;i<=10000000;i++)
	{
		int sum1=i,lo=0;
		for(int j=1;j<=cnt&&sum[j]<=n;j++)
		{
			while(sum1%sum[j]==0)sum1/=sum[j],lo++;
			a[i]=max(a[i],lo);
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		long long ans2=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			if(n*i==0)ans2+=i*a[n/i];
		}
		cout<<ans2<<endl;
	}
}

#include<iostream>
using namespace std;
int n,f[5005],l[5005][5005],a[5005],ans;
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i]=1;
		l[i][1]=a[i];
	}
	for(int i=n;i>=1;i--)
	{
		int cnt=i;
		for(int j=i+1;j<=n;j++)
			if(a[i]<a[j])
				if(f[j]+1>f[i])
				{
					cnt=j;
					f[i]=f[j]+1;
				}
				else if(f[j]+1==f[i])
				{
					for(int k=1;k<=f[j];k++)
					{
						if(l[cnt][k]<l[j][k])
						{
							cnt=j;
							break;
						}
						if(l[cnt][k]>l[j][k])
							break;
					}
				}	
		if(cnt!=i)
			for(int j=1;j<=f[cnt];j++)
				l[i][j+1]=l[cnt][j];
		if(f[i]>f[ans])
			ans=i;
		else if(f[i]==f[ans])
		{
			bool flag=0;
			for(int j=1;j<=f[i];j++)
			{
				if(l[ans][j]<l[i][j])
				{
					flag=1;
					break;
				}
				if(l[ans][j]>l[i][j])
					break;
			}
			if(flag==1)
				ans=i;
		}
	}
	printf("%d\n",f[ans]);
	for(int i=1;i<=f[ans];i++)
	{
		printf("%d ",l[ans][i]);
	}
}


#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005],dpk[5005];
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	a[0]=0;
	for(int i=n;i>=0;i--)
	{
		dpk[i]=n+1;
		for(int j=n;j>i;j--)
		{
			if(a[i]<a[j])
			{
				if(dp[j]>dp[dpk[i]])
				{
					dpk[i]=j;
				}
				else if(dp[j]==dp[dpk[i]]&&a[j]>a[dpk[i]])
				{
					dpk[i]=j;
				}
			}
		}
		dp[i]=dp[dpk[i]]+1;
	}
	printf("%d\n",dp[0]-1);
	for(int i=dpk[0];i<=n;i=dpk[i])
	{
		printf("%d ",a[i]);
	}
	return 0;
}

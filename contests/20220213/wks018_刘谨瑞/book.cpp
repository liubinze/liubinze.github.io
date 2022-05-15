#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
long long b[100005];
long long dp[2][100005];
long long ans=1000000000000000000;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[1][i]=b[i];
	}
	for(int j=2,cnt=0;j<=m;j++,cnt^=1)
	{
		for(int i=1;i<=n;i++)
		{
			dp[cnt][i]=1000000000000000000;
			for(int k=j-1;k<i;k++)
			{
				dp[cnt][i]=min(dp[cnt][i],max(dp[cnt^1][k],b[i]-b[k]));
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans=min(ans,dp[m&1][i]);
	}
	printf("%lld",ans);
	return 0;
}
//i本书 j个人 
//b为前缀和 
//dp[i][j]=min(max(dp[0~i-1][j-1],b[i]-b[1~i-1]))
//dp[i][j]=b[i]+min(max(dp[0~i-1][j-1]-b[i],-b[1~i-1]))
//dp[i][j]=b[i]+min(max(dp[0~i-1][j-1]-b[i],-b[1~i-1]))

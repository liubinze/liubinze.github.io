#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
long long sum[N],dp[5005][5005],ans=0x3f3f3f3f3f;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum[i]=sum[i-1]+a[i];
	memset(dp,0x3f3f3f,sizeof dp);
	for(int i=1;i<=n;i++)dp[1][i]=sum[i];
	for(int i=2;i<=m;i++)
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<j;k++)
			{
				long long t=sum[j]-sum[k];
				if(max(t,dp[i-1][k])<dp[i][j])dp[i][j]=max(t,dp[i-1][k]);
			}
		}
	for(int i=m;i<=n;i++)ans=min(dp[m][i],ans);
	printf("%lld\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
long long x[2005],q[2005],dp[2005][2005],ans=1e9;
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n;a++) scanf("%lld",&x[a]),q[a]=q[a-1]+x[a];
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0]=0;
	for(int a=1;a<=n;a++)
	{
		int h=min(a,m);
		for(int b=1;b<=h;b++)
		{
			for(int c=0;c<a;c++)
			{
				dp[a][b]=min(dp[a][b],max(dp[c][b-1],q[a]-q[c]));
			}
		}
	}
	for(int a=m;a<=n;a++) ans=min(ans,dp[a][m]);
	printf("%lld",ans);
}

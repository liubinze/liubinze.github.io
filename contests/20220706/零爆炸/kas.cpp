#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
int c[503],dp[503][100003];
int main()
{
	freopen("kas.in","r",stdin),freopen("kas.out","w",stdout);
	int n,s=0,t;
	scanf("%d",&n),memset(dp,0x80,sizeof(dp));
	for(int i=0;i<n;i++)
		scanf("%lld",c+i),s+=c[i];
	dp[0][t=s>>1]=0;
	for(int i=0,_=0;i<n;_+=c[i++])
		for(int k=min(t,_),j=-k;j<=k;j++)
		{
			dp[i+1][j+t]=max(dp[i+1][j+t],dp[i][j+t]);
			if(j+c[i]>=-t&&j+c[i]<=t)
				dp[i+1][j+c[i]+t]=max(dp[i+1][j+c[i]+t],dp[i][j+t]+c[i]);
			if(j-c[i]>=-t&&j-c[i]<=t)
				dp[i+1][j-c[i]+t]=max(dp[i+1][j-c[i]+t],dp[i][j+t]+c[i]);
		}
	printf("%d",s-(dp[n][t]>>1));
	return 0;
}

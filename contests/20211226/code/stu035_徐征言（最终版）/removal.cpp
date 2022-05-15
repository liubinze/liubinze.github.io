#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[100005];
bool dp[100005][15][15];
struct X
{
	int x,y,z;
}j[100005][15][15],h[100005][15];
int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(int a=1;a<=n;a++) scanf("%d",&x[a]);
		dp[n+1][0][0]=1;
		h[n+1][0].x=n+1;
		h[n+1][0].y=0;
        h[n+1][0].z=0;
		for(int a=n;a>=0;a--)
		{
			for(int b=0;b<=m+1;b++)
			{
				for(int c=k;c>=0;c--)
				{
					if(x[a]==c)
					{
					    dp[a][b][c]=dp[h[a+1][b].x][h[a+1][b].y][h[a+1][b].z];
					    j[a][b][c]=h[a+1][b];
					}
					else
					{
					    dp[a][b][c]=dp[a+1][b-1][c];
						j[a][b][c].x=a+1;
						j[a][b][c].y=b-1;
						j[a][b][c].z=c;	
					}
					if(dp[a][b][c]==1) 
					{
						h[a][b].x=a;
						h[a][b].y=b;
						h[a][b].z=c;	
					}
				}
			}
		}
		for(int d=1;d<=k;d++)
		{
			if(dp[0][m+1][d]==1)
			{
				for(int a=0,b=m+1,c=d;a<=n&&b>=0&&c>0;)
				{
					if(j[a][b][c].y!=b-1) printf("%d ",c);
					int a1=j[a][b][c].x,b1=j[a][b][c].y,c1=j[a][b][c].z;
					a=a1,b=b1,c=c1;
				}
				printf("\n");
				break;
			}
		}
	}
}

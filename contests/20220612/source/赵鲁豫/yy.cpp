#include<iostream>
#include<cstring>
using namespace std;
int t,n,m,ans;
bool ina[15],inb[15],y[15],pam[15][15];
void dfs(int u,int d,int sum)
{
	if(u>=2*n)
	{
		if(pam[1][d]&&y[1]==0)
			ans=min(ans,sum+1);
		else
			ans=min(ans,sum);
		return ;
	}
	if(u%2==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(!inb[i])
			{
				inb[i]=1;
				if(pam[d][i]&&y[d]==0)
				{
					y[d]=1;
					dfs(u+1,i,sum+1);
					y[d]=0;
				}	
				else
					dfs(u+1,i,sum);
				inb[i]=0;
			}
		}
	}
	if(u%2==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(!ina[i])
			{
				ina[i]=1;
				if(pam[i][d])
				{
					y[i]=1;
					dfs(u+1,i,sum+1);
					y[i]=0;
				}
				else
					dfs(u+1,i,sum);
				ina[i]=0;
			}
		}
	}
}
int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(pam,0,sizeof pam);
		ans=n;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			pam[x][y]=1;
		}
		ina[1]=1;
		dfs(1,1,0);
		ina[1]=0;
		printf("%d\n",ans);
	}
}


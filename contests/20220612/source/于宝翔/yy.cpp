#include<bits/stdc++.h>
using namespace std;

const int N=20;

int t,n,m,ans;
int a[N];
bool mark[N][N],vis[N];

void dfs1(int k)
{
	if(k==2*n)
	{
		int tot=0;
		for(int i=3;i<2*n;i+=2)
			if(mark[a[i]][a[i+1]]||mark[a[i]][a[i-1]])
				tot++;
		if(mark[a[1]][a[n+n]]||mark[a[1]][a[2]])tot++;
		ans=min(ans,tot);
		return;
	}
	if(k&1)
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				a[k+1]=i;
				dfs1(k+1);
				vis[i]=false;
			}
	}
	else
	{
		for(int i=n+1;i<=n+n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				a[k+1]=i;
				dfs1(k+1);
				vis[i]=false;
			}
	}
}

void dfs2(int k)
{
	if(k==2*n)
	{
		int tot=0;
		for(int i=3;i<2*n;i+=2)
			if(mark[a[i]][a[i+1]]||mark[a[i]][a[i-1]])
				tot++;
		if(mark[a[1]][a[n+n]]||mark[a[1]][a[2]])tot++;
		ans=min(ans,tot);
		return;
	}
	if(k%2==0)
	{
		for(int i=1;i<=n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				a[k+1]=i;
				dfs2(k+1);
				vis[i]=false;
			}
	}
	else
	{
		for(int i=n+1;i<=n+n;i++)
			if(!vis[i])
			{
				vis[i]=true;
				a[k+1]=i;
				dfs2(k+1);
				vis[i]=false;
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
		memset(mark,false,sizeof mark);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			mark[x][y+n]=true;
			mark[y+n][x]=true;
		}
		ans=9999999;
		dfs1(0);
		dfs2(0);
		printf("%d\n",ans);
	}
	return 0;
}

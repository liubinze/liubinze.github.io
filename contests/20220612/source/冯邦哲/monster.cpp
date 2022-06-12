#include<bits/stdc++.h>
using namespace std;
struct two
{
	int u,v;
}e[40000<<1];
int n,m,head[40000],link[40000],vis[40000],cnt,t;
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].u=head[u];
	head[u]=cnt;
}
int dfs(int u)
{
	for(int i=head[u];i;i=e[i].u)
	{
		int v=e[i].v;
		if(vis[v])continue;
		vis[v]=1;
		if(!link[v]||dfs(v))
		{
			link[u]=v;
			return 1;
		}
	}
	return 0;
}
int max_match()
{
	int cnt=0;
	memset(link,0,sizeof link);
	for(int i=1;i<=n+m;i++)
	{
		memset(vis,0,sizeof vis);
		cnt+=dfs(i);
	}
	return cnt;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int cnt1=0;
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='*')
				{
					add(i+n,j);
					add(j+n,i);
				}
			}
		}
		int ans=max_match();
		printf("%d\n",ans/2);
	}
	return 0;
}

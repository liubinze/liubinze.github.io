#include<bits/stdc++.h>
using namespace std;

int T,n,m,tot,ans;
char a[30][30];
int link[100];
bool vis[100],mark[60][60];

vector<int>G[100];

struct node
{
	int x,y;
}b[900];

void init()
{
	for(int i=1;i<=n+m;i++)G[i].clear();
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(mark,0,sizeof mark);
	tot=0;
}

bool dfs(int u)
{
	for(int v:G[u])
	{
		if(vis[v])continue;
		vis[v]=1;
		if(link[v]==-1||dfs(link[v]))
		{
			link[v]=u;
			return 1;
		}
	}
	return 0;
}

int max_match()
{
	int cnt=0;
	memset(link,-1,sizeof link);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		cnt+=dfs(i);
	}
	return cnt;
}

void add(int x,int y)
{
	G[x].push_back(y);
	G[y].push_back(x);
}

int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='*')
				{
					b[++tot].x=i;
					b[tot].y=j;
					add(i,j+n);
					mark[i][j+n]=mark[j+n][i]=1;
				}
			}
		}
		for(int i=1;i<=tot;i++)
		{
			int X=b[i].x;
			for(int j=1;j<=tot;j++)
			{
				int Y=b[j].y;
				if(mark[X][Y+n])continue;
				add(X,Y+n);
				mark[X][Y+n]=mark[Y+n][X]=1;
			}
		}	
		printf("%d\n",max_match()/2-1);
	}
	return 0;
}

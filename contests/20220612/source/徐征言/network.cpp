#include<bits/stdc++.h>
using namespace std;
int n,m,A,B,x,y,t;
bool vis[5005];
vector<int> son[5005];
struct X
{
	int x,y,id,ans;
}j[5005];
bool cmp(X a,X b)
{
	return a.x<b.x||(a.x==b.x&&a.y>b.y);
}
void add_edge(int x,int y)
{
	son[x].push_back(y);
}
void dfs(int k)
{
	if(vis[k]==1) return;
	vis[k]=1;
	for(int a=0;a<son[k].size();a++)
	{
		int s=son[k][a];
		dfs(s);
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int a=1;a<=n;a++)
	{
		scanf("%d%d",&j[a].x,&j[a].y);
		j[a].id=a;
	}
	for(int a=1;a<=m;a++)
	{
		scanf("%d%d%d",&x,&y,&t);
		if(t==1) add_edge(x,y);
		else
		{
			add_edge(x,y);
			add_edge(y,x);
		}
	}
	for(int a=1;a<=n;a++)
	{
		if(j[a].x==0)
		{
			memset(vis,0,sizeof(vis));
			dfs(a);
			for(int b=1;b<=n;b++)
			{
				if(vis[b]==1&&j[b].x==A) j[a].ans++;
			}
		}
	}
	sort(j+1,j+1+n,cmp);
	for(int a=1;a<=n;a++)
	{
		if(j[a].x!=0) break;
		printf("%d\n",j[a].ans);
	}
}

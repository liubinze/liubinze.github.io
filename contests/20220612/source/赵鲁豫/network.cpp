#include<iostream>
#include<algorithm>
#include<stack>
#include<bitset>
using namespace std;
int n,m,A,B;
struct nod{
	int x,y;
}a[300005];
struct nd{
	int u,y;
}dc[300005];
int dc1,xc1,xc[300005];
bool cmp(nd a,nd b)
{
	return a.y>b.y;
}
struct graph{
	struct node{
		int to,next;
	}e[1800005];
	int lg[300005],cnt;
	void add(int u,int v)
	{
		e[++cnt].to=v;
		e[cnt].next=lg[u];
		lg[u]=cnt;
	}
}g1,g2;
int dfn[300005],low[300005],scc[300005],tot,sc;
stack<int> s;
void tarjan(int u)
{
	dfn[u]=low[u]=++tot;
	s.push(u);
	for(int i=g1.lg[u];i;i=g1.e[i].next)
	{
		int v=g1.e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!scc[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		sc++;
		while(s.top()!=u)
		{
			scc[s.top()]=sc;
			s.pop();
		}
		scc[u]=sc;
		s.pop();
	}
}
bitset<30005> bt[30005];
bool vis[300005];
void dfs(int u)
{
	vis[u]=1;
	for(int i=g2.lg[u];i;i=g2.e[i].next)
	{
		int v=g2.e[i].to;
		if(vis[v])
			bt[u]|=bt[v];
		else
		{
			dfs(v);
			bt[u]|=bt[v];
		}
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x==0)
			dc[++dc1].u=i,dc[dc1].y=a[i].y;
		if(a[i].x==A)
			xc[++xc1]=i;
	}
	sort(dc+1,dc+dc1+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int ui,vi,ti;
		scanf("%d%d%d",&ui,&vi,&ti);
		g1.add(ui,vi);
		if(ti==2) g1.add(vi,ui);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int i=1;i<=n;i++)
	{
		for(int j=g1.lg[i];j;j=g1.e[j].next)
		{
			int v=g1.e[j].to;
			if(scc[i]!=scc[v])
				g2.add(scc[i],scc[v]);
		}
	}
	for(int i=1;i<=sc;i++)
		bt[i][i]=1;
	for(int i=1;i<=sc;i++)
		if(!vis[i])
			dfs(i);
	for(int i=1;i<=dc1;i++)
	{
		int sum=0;
		for(int j=1;j<=xc1;j++)
		{
			if(bt[scc[dc[i].u]][scc[xc[j]]])
				sum++;
		}
		printf("%d\n",sum);
	}
}


#include<bits/stdc++.h>
using namespace std;

const int N=5005,M=10005;

int n,m,A,B,num,top,scc,tot;
int dfn[N],low[N],pos[N],cnt[N],stk[N],deg[N];
bool ins[N];
bitset<N> bs[N];
queue<int> q;
struct aaa
{
	int x,y;
}a[N];
struct bbb
{
	int dat,y;
}ans[N];
struct edge
{
	int idx;
	int head[N];
	struct node
	{
		int fr,to,ne;
	}e[2*M];
	
	void add(int x,int y)
	{
		e[++idx].fr=x;
		e[idx].to=y;
		e[idx].ne=head[x];
		head[x]=idx;
	}
	
}e1,e2;

void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	stk[++top]=u,ins[u]=true;
	for(int i=e1.head[u];i;i=e1.e[i].ne)
	{
		int v=e1.e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v])low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		int v;
		scc++;
		do
		{
			v=stk[top--];
			pos[v]=scc;
			if(a[v].x==A)cnt[scc]++;
			ins[v]=false;
		}while(u!=v);
	}
}

bool cmp(bbb x,bbb y)
{
	return x.y>y.y;
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i].x=x,a[i].y=y;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,t;
		scanf("%d%d%d",&x,&y,&t);
		if(t==1)e1.add(x,y);
		else e1.add(x,y),e1.add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=e1.idx;i++)
	{
		int x=e1.e[i].fr,y=e1.e[i].to;
		if(pos[x]!=pos[y])
		{
			e2.add(pos[y],pos[x]);
			deg[pos[x]]++;
		}
	}
	for(int i=1;i<=scc;i++)
		if(deg[i]==0)
			q.push(i);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		bs[u][u]=true;
		for(int i=e2.head[u];i;i=e2.e[i].ne)
		{
			int v=e2.e[i].to;
			bs[v]|=bs[u];
			if(--deg[v]==0)q.push(v);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i].x==0)
		{
			tot++;
			int ii=pos[i];
			for(int j=1;j<=scc;j++)
				if(bs[ii][j])
					ans[tot].dat+=cnt[j];
			ans[tot].y=a[i].y;
		}
	}
	sort(ans+1,ans+tot+1,cmp);
	for(int i=1;i<=tot;i++)
	{
		printf("%d\n",ans[i].dat);
	}
	return 0;
}

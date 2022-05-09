#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5,M=1e5+5,inf=0x3f3f3f3f;
int n,m,c;
int last[N],en[N],ne[N],w[N],tot;
int dis[M],l[M];
bool vis[M];

void add(int u,int v,int a)
{
	en[++tot]=v;
	ne[tot]=last[u];
	last[u]=tot;
	w[tot]=a;
}

struct node
{
	int id,d;
};

bool operator <(node a,node b)
{
	return a.d>b.d;
}

priority_queue<node>q;

void djstra()
{
	q.push({1,0});
	while(!q.empty())
	{
		node t=q.top();
		q.pop();
		if(vis[t.id])continue;
		vis[t.id]=1;
		for(int i=last[t.id];i;i=ne[i])
		{
			int v=en[i];
			if(l[t.id]==l[v]+1||l[t.id]==l[v]-1)w[i]=min(w[i],c);
			if(dis[t.id]+w[i]<dis[v])
			{
				dis[v]=dis[t.id]+w[i];
				q.push({v,dis[v]});
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(l[t.id]==l[i]-1||l[t.id]==l[i]+1)
			{
				if(dis[t.id]+c<dis[i])
				{
					dis[i]=dis[t.id]+c;
					q.push({i,dis[i]});
				}
			}
		}
	}
}

int main()
{
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)scanf("%d",&l[i]);
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=2;i<=n;i++)dis[i]=inf;
	djstra();
	if(dis[n]==inf)printf("-1\n");
	else printf("%d\n",dis[n]);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N=300005,M=900005;
int n,m,A,B,cnt;
vector<int>G[N];
vector<int>p;
int x[N],y[N],f[N];
bool vis[N];

struct node
{
	int t,ans;
}a[N];

bool cmp(node a,node b)
{
	return a.t>b.t;
}

void dfs(int u)
{
	if(x[u]==A&&!vis[u])cnt++;
	vis[u]=1;
	for(int v:G[u])
	{
		if(!vis[v])dfs(v);
	}
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(x[i]==0)p.push_back(i);
	}
	int u,v,T;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&T);
		G[u].push_back(v);
		if(T==2)G[v].push_back(u);
	}
	int tot=0;
	for(int u:p)
	{
		cnt=0;
		memset(vis,0,sizeof vis);
		dfs(u);
		a[++tot].ans=cnt;
		a[tot].t=y[u];
	}
	sort(a+1,a+1+tot,cmp);
	for(int i=1;i<=tot;i++)printf("%d\n",a[i].ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct two
{
	int u,v;
}e[1000001];
int cnt,n,m,t,cnt1,cnt2,top,ans=0,vis2[10000001],mp[1200][1200],d[100001],dfn[100000001],head[1000000],ans1,low[1000001],belong[1000001];
void add(int u,int v)
{
	e[++cnt].u=head[u];
	head[u]=cnt;
	e[cnt].v=v;
}
void tarjan(int x)
{
	low[x]=dfn[x]=++cnt2;
	d[++top]=x;
	vis2[x]=1;
	for(int i=head[x];i!=-1;i=e[i].u)
	 if(!dfn[e[i].v])
	  {
	  	tarjan(e[i].v);
	  	low[x]=min(low[x],low[e[i].v]);	
	  }
	  else
	   if(vis2[e[i].v]&&low[x]>dfn[e[i].v]) low[x]=dfn[e[i].v];
	if(low[x]==dfn[x])
	 {
	 	++cnt1;
	 	int b;
	 	do{
	 		b=d[top--];
	 		belong[b]=cnt1;
	 		vis2[b]=0;
		 }while(x!=b);
	 }
	return;
}
void solve()
{
	for(int i=n+1;i<=n+n;i++)if(!dfn[i])tarjan(i);
	for(int i=n+1;i<=n+n;i++)if(belong[i]!=belong[i^1])ans++;
}
int x[1000001],y[1000001];
int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(head,-1,sizeof head);
		memset(vis2,0,sizeof vis2);
		memset(dfn,0,sizeof dfn);
		memset(low,0,sizeof low);
		cnt=cnt1=cnt2=top=ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]),add(x[i]+n,y[i]+n);
		solve();
		printf("%d\n",(n-ans)/2);
	}
}

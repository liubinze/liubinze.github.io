#include<bits/stdc++.h>
using namespace std;
int n,m,C,x,y,z,dis[800005];
bool u[800005];
vector<int> f[800005],son[800005],cost[800005];
struct X
{
	int dis,id;
}j;
bool operator < (X a,X b)
{
	return a.dis>b.dis;
}
priority_queue<X> q;
int main()
{
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
	scanf("%d%d%d",&n,&m,&C);
	for(int a=1;a<=n;a++)
	{
		scanf("%d",&x);
		f[x].push_back(a);
	}
	for(int a=1;a<=m;a++)
	{
		scanf("%d%d%d",&x,&y,&z);
		son[x].push_back(y);
		cost[x].push_back(z);
		son[y].push_back(x);
		cost[y].push_back(z);
	}
	for(int a=1;a<=n;a++)
	{
		if(f[a].size()>0)
		{
			if(a<n)
			{
		        son[2*n+a].push_back(n+a+1);
		        cost[2*n+a].push_back(C);
			}
			if(a>1)
			{	
		        son[2*n+a].push_back(n+a-1);
		        cost[2*n+a].push_back(C);
			}
		}
		for(int b=0;b<f[a].size();b++)
		{
			int s=f[a][b];
			son[n+a].push_back(s);
		    cost[n+a].push_back(0);
		    son[s].push_back(2*n+a);
	 	    cost[s].push_back(0);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	j.id=1;
	j.dis=0;
	q.push(j);
	while(!q.empty())
	{
		int id=q.top().id;
		q.pop();
		if(u[id]==1) continue;
		u[id]=1;
		for(int a=0;a<son[id].size();a++)
		{
			int s=son[id][a],co=cost[id][a];
			if(dis[id]+co<dis[s])
			{
				dis[s]=dis[id]+co;
				j.id=s;
				j.dis=dis[s];
				q.push(j);
			}
		}
	}
	if(dis[n]==0x3f3f3f3f) printf("-1 ");
	else printf("%d ",dis[n]);
}

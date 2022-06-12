#include <bits/stdc++.h>
using namespace std;

const int N = 5e2;

struct node
{
	int y,next;
}e[N | 5];

int n,m,tot,link[N | 5],head[N | 5],ans;
bool road[N | 5];

bool Find(int u)
{
//	printf("%d\n",u);
	for(int i = head[u];i;i = e[i].next)
	{
		int v = e[i].y;
		if(!road[v])
		{
			road[v] = true;
//			printf("%d %d\n",v,link[v]);
			if(!link[v] || Find(link[v]))
			{
				link[v] = u;
				return true;
			}
		}
	}
	return false;
}

void add(int u,int v)
{
	e[++tot].y = v;
	e[tot].next = head[u];
	head[u] = tot;
}

void init()
{
	memset(head,0,sizeof(head));
	memset(e,0,sizeof(e));
	memset(link,0,sizeof(link));
	tot = ans = 0;
}

int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d %d",&n,&m);
		for(int i = 1;i <= m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			add(x,y + n);
		}
		for(int i = 1;i <= n;i++)
		{
			bool flag = true;
			memset(road,false,sizeof(road));
			if(!Find(i)) ans++;
		}
		printf("%d\n",ans);
		
	}
	return 0;
}

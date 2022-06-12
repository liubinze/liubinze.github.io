#include<bits/stdc++.h>
using namespace std;

const int N = 105;

int n,m;
stack<int>G[N],g[N];

signed main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= n; i++)
		{
			while(!G[i].empty()) G[i].pop();
			while(!g[i].empty()) g[i].pop();
			for(int j = 1; j <= n; j++)
			{
				G[i].push(j);
			}
		}
		for(int i = 1,x,y; i <= m; i++)
		{
			scanf("%d %d",&x,&y);
			while(!G[y].empty())
			{
				if(G[y].top() == x)
				{
					G[y].pop();
					break;
				}
				g[y].push(G[y].top());
				G[y].pop();
			}
			while(!g[y].empty())
			{
				G[y].push(g[y].top());
				g[y].pop();
			}
		}
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(G[i].size() < 2)
			{
				ans++;
			}
		}
		printf("%d\n",min(ans,n - ans));
	}
	return 0;
}

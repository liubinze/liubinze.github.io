#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n,m,a,b;
vector<int>G[N];
map<int,pair<int,int> >id;
int flag[N];
int ans;

void dfs(int x)
{
	flag[x] = 1;
	ans++;
	for(int i : G[x]) if(!flag[i]) dfs(i);
}

signed main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++)
	{
		int x,y;
		cin >> x >> y;
		id[i] = {x,y};
	}
	for(int i = 1; i <= m; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		G[x].push_back(y);
		if(z == 2) G[y].push_back(x);
	}
	for(int i = 1; i <= n; i++)
	{
		memset(flag,0,sizeof flag);
		ans = 0;
		dfs(i);
		if(id[i].first == 0) cout << ans / 2 << endl;
	}
	
	return 0;
}

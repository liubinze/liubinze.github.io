#include<bits/stdc++.h>
using namespace std;

const int N = 31;

int n,m;
int ans,h[N],l[N];
char temp[N];
bool mp[N][N];

int check(int x,int y) {return h[x] + l[y];}

void cut(int x,int y)
{
	for(int i = 1; i <= n; i++) mp[i][y] = 0;
	for(int j = 1; j <= m; j++) mp[x][j] = 0;
	h[x] = 0,l[y] = 0;
}

signed main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans = 0;
		memset(h,0,sizeof h);
		memset(l,0,sizeof l);
		scanf("%d %d",&n,&m);
		for(int i = 1; i <= n; i++)
		{
			scanf("%s",temp + 1);
			for(int j = 1; j <= m; j++) if(temp[j] == '*') mp[i][j] = 1,h[i]++,l[j]++;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				if(mp[i][j])
				{
					int lx,ly,Ans = 0;
					bool flag = 0;
					for(int k = 1; k <= m; k++) for(int l = 1; l <= n; l++) if(mp[l][k]) if(check(i,k) > Ans) Ans = check(i,k),lx = i,ly = k;
					for(int k = 1; k <= n; k++) for(int l = 1; l <= m; l++) if(mp[k][l]) if(check(k,j) > Ans) Ans = check(k,j),lx = k,ly = j;
					cut(lx,ly);
					h[lx] = 0,l[ly] = 0;
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

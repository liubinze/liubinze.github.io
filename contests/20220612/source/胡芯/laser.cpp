#include <bits/stdc++.h>
#pragma target ("avx")
#pragma GCC optimize (1)
#pragma GCC optimize (2)
#pragma GCC optimize (3)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#define _rep(i,a,b) for(register int i(a);i^(b+1);i=-~i)
using namespace std;

const int N(501);

int t;
int n,m;
char s[N][N];
char sp[N][N];
char kp[N][N];
bool flag=false;
bool zp;
void dfs(int x,int y)
{
	if (flag) return ;
	if (x > n)
	{
		_rep(i,1,n)
		{
			_rep(j,1,m)
			{
				if (sp[i][j] == '-')
				{
					zp=false;
					for (int p=0;p<=m;p++)
					{
						switch (kp[i][p])
						{
							case '.': kp[i][p]='x';break;
							case '#': break;
							case 'S': zp=true;break;
						}
						if (zp) return ;
					}
				}
				else if (sp[i][j] == '|')
				{
					zp=false;
					for (int p=0;p<=n;p++)
					{
						switch (kp[p][j])
						{
							case '.': kp[p][j]='x';break;
							case '#': break;
							case 'S': zp=true;break;
						}
						if (zp) return ;
					}
				}
			}
		}
		return ;
	}

	if (s[x][y] == '.')
	{
		if (flag) return ;
		sp[x][y]=s[x][y];
		kp[x][y]=s[x][y];

		if (y==m) dfs(x+1,1);
		else dfs(x,y+1);
	}
	else if (s[x][y] == '#')
	{
		if (flag) return ;
		sp[x][y]=s[x][y];
		kp[x][y]=s[x][y];

		if (y==n) dfs(x+1,1);
		else dfs(x,y+1);
	}
	else
	{
		if (flag) return ;
		kp[x][y]='S';
		sp[x][y]='-';
		if (y==n) dfs(x+1,1);
		else dfs(x,y+1);
		sp[x][y]='|';
		if (y==n) dfs(x+1,1);
		else dfs(x,y+1);
	}
}
int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	
	scanf("%d",&t);
	while (t--)
	{
		flag=false;
		scanf("%d %d",&n,&m);
		if (n*m>=27) puts("no");
		_rep(i,1,n) cin>>s[i]+1;
		dfs(1,1);
		if (!flag) puts("no");
		else
		{
			_rep(i,1,n)
			{
				_rep(j,1,m)
				{
					putchar(sp[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}

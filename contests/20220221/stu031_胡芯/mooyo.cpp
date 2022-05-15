#include <bits/stdc++.h>
using namespace std;

int n,k;
char my[11];
int dx[5]=
{
	0,1,-1,0,0
};
int dy[5]=
{
	0,0,0,1,-1
};

int s[101][11];
bool use[101][11];

struct node
{
	int x;
	int y;
};
vector<node> q;

void print()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			printf("%d",s[i][j]);
		}
		puts("");
	}
}

void dfs(int x,int y)
{
	use[x][y]=1;
	q.push_back((node)
	{
		x,
		y
	});
	for (int i=1; i<=4; i++)
	{
		int xx,yy;
		xx=dx[i]+x;
		yy=dy[i]+y;
		if (!(xx<0 || xx>n || yy<0 || yy>10))
		{
			if (s[xx][yy] == s[x][y] && !use[xx][yy])
			{
				dfs(xx,yy);
			}
		}
	}
}
void work()
{
	if (q.size() >= k)
	{
		for (int i=0; i<q.size(); i++)
		{
			s[q[i].x][q[i].y]=0;
		}
	}
	for (int i=n-1; i>=1; i--)
	{
		for (int j=1; j<=10; j++)
		{
			int w,e;
			w=i;
			e=j;
			while (s[w][e] != 0 && s[w+1][e] == 0 && w!=n)
			{
				swap(s[w][e],s[w+1][e]);
				w+=1;
			}
		}
	}
}

int main()
{
	freopen("mooyo.in","r",stdin);
	freopen("mooyo.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1; i<=n; i++)
	{
		cin>>my;
		int len=strlen(my);
		for (int j=0; j<len; j++)
		{
			s[i][j+1]=my[j]-'0';
		}
	}
	work();
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=10; j++)
		{
			if (s[i][j] > 0)
			{
				dfs(i,j);
				work();
				q.clear();
				memset(use,false,sizeof (use));
			}
		}
	}
	work();
	print();
	return 0;
}																						  			  

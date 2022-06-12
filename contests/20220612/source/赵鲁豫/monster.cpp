#include<iostream>
#include<cstring>
using namespace std;
int t;
int n,m,ans;
char c;
struct node{
	int to,next;
}e[10005];
int lg[1005],cnt;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=lg[u];
	lg[u]=cnt;
}
bool st[1005];
int match[1005];
bool fd(int u)
{
	for(int i=lg[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!st[v])
		{
			st[v]=1;
			if(!match[v]||fd(match[v]))
			{
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(lg,0,sizeof lg);
		memset(match,0,sizeof match);
		cnt=0;ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf(" %c",&c);
				if(c=='*')
					add(i,j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			memset(st,0,sizeof st);
			if(fd(i)) ans++;
		}
		printf("%d\n",ans/2);
	}
}


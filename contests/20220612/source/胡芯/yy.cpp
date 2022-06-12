#include <bits/stdc++.h>
#pragma target ("avx")
#pragma GCC optimize (1)
#pragma GCC optimize (2)
#pragma GCC optimize (3)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#define _rep(i,a,b) for(register int i(a);i^(b+1);i=-~i)
using namespace std;

const int N=10;

int t;
int n,m;
int x,y;
int res=0;
struct node
{
	int x;
	int y;
	int nxt;
} e[N*N+3];
int k,last[N];
inline void add(int x,int y)
{
	e[++k]=(node){
		x,y,last[x]
	};
	last[x]=k;
	
	e[++k]=(node){
		y,x,last[y]
	};
	last[y]=k;
}
bool road[N*N+3];
int link[N];
inline bool find(int u)
{
	for (int i=last[u];i>0;i=e[i].nxt)
	{
		int v=e[i].y;
		if (!road[v])
		{
			road[v]=true;
			if (!link[v] || find(link[v]))
			{
				link[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	
	scanf("%d",&t);
	while (t--)
	{
		k=0;
		memset(last,-1,sizeof last);
		memset(e,0,sizeof e);
		scanf("%d %d",&n,&m);
		_rep(i,1,m)
		{
			scanf("%d %d",&x,&y);
			add(x,y);
		}
		res=0;
		memset(link,0,sizeof link);
		_rep(i,1,n)
		{
			memset(road,false,sizeof road);
			if (find(i) == true) res=-~res;
		}
		printf("%d\n",n-res);
	}
	return 0;
}

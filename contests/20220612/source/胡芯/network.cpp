#include <bits/stdc++.h>
#include <cstdio>
#include <cctype>
#include <vector>
#pragma target ("avx")
#pragma GCC optimize (1)
#pragma GCC optimize (2)
#pragma GCC optimize (3)
#pragma GCC optimize ("inline")
#pragma GCC optimize ("Ofast")
#define _rep(i,a,b) for(register int i(a);i^(b+1);i=-~i)
using namespace std;

const int size=1<<20;
char buf[size],*p1,*p2;
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,size,stdin),p1==p2)?EOF:*p1++)
inline void read(int &x)
{
	x=0;
	char ch;
	while (!isdigit(ch = gc));
	do
	{
		x=x*10+ch-'0';
	}
	while (isdigit(ch = gc));
}


const int N(3.0E5+1);
const int M(2.0E6+1);

int n,m;
int A,B;
int x,y,t;
struct city
{
	int id;
	int y;
};
map<int,int> east;
vector<city> west;
struct node
{
	int x;
	int y;
	int nxt;
} e[M+3];
int k,last[N];
inline void add(int x,int y,int key)
{
	e[++k]=(node)
	{
		x,y,last[x]
	};
	last[x]=k;
	if (key == 1) return ;
	e[++k]=(node)
	{
		y,x,last[y]
	};
	last[y]=k;
}
inline bool cmp(city a,city b)
{
	return a.y>b.y;
}
bool vis[N];
int res[N];
inline void bfs(city u,int p)
{
	memset(vis,false,sizeof vis);
	queue<int> sp;
	for (int i=last[u.id]; i>0; i=e[i].nxt) sp.push(e[i].y),vis[e[i].y]^=1;
	while (!sp.empty())
	{
		int v=sp.front();
		sp.pop();
		if (east[v] != 0)
		{
			++res[p];
		}
		for (int i=last[v]; i>0; i=e[i].nxt)
		{
			if (!vis[e[i].y])
			{
				sp.push(e[i].y);
				vis[e[i].y]^=1;
			}
		}
	}
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);

	read(n);
	read(m);
	read(A);
	read(B);
	_rep(i,1,n)
	{
		read(x);
		read(y);
		if (x == 0) west.push_back((city)
		{
			i,y
		});
		else if (x == A) ++east[i];
	}
	_rep(i,1,m)
	{
		read(x);
		read(y);
		read(t);
		add(x,y,t);
	}
	sort (west.begin(),west.end(),cmp);
	_rep(i,0,west.size()-1)
	{
		bfs(west[i],i);
	}
	_rep(i,0,west.size()-1)
	{
		printf("%d\n",res[i]);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1 << 20;  
char buf[SIZE],*p1,*p2;  
#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin),p1==p2)?EOF:*p1++)  

void read(int &x) 
{  
    x = 0;  
    char ch;  
    while(!isdigit(ch = gc));  
    do 
	{  
        x = x * 10 + ch - '0';  
    }while(isdigit(ch = gc));  
} 

const int N = 3e5,M = 9e5;

struct node
{
	int y,next;
}e[M | 5],r[M | 5];

struct nodee
{
	int idx,ans;
}print[N | 5];

bool operator < (nodee x,nodee y)
{
	return x.idx > y.idx;
}

int n,m,A,B,dfn[N | 5],low[N | 5],head[N | 5],head1[N | 5],belong[N | 5],tot,tot1,cnt,cnt_,x[N | 5],y[N | 5],mark[N | 5],ans[N | 5],vis[N | 5],print_num;
int tar[N | 5],top;

void dfs(int u)
{
	dfn[u] = low[u] = ++cnt;
	tar[++top] = u;
	for(int i = head[u];i;i = e[i].next)
	{
		int v = e[i].y;
		if(!dfn[v]) dfs(v),low[u] = min(low[u],low[v]);
		else if(!belong[v]) low[u] = min(low[u],dfn[v]);
	}
	if(dfn[u] == low[u])
	{
		cnt_++;
		int t;
		do
		{
			t = tar[top];
			belong[t] = cnt_;
			top--;
		}while(t != u);
//	printf("!");
	}
}

void add1(int u,int v)
{
	e[++tot].y = v;
	e[tot].next = head[u];
	head[u] = tot;
}

void add2(int u,int v)
{
	r[++tot1].y = v;
	r[tot1].next = head1[u];
	head1[u] = tot1;
}

void dfs1(int u,int st)
{
//	printf("%d %d %d\n",u,vis[u],st);
	if(vis[u] == st) 
	{
//		printf("!");
		return ;
	}
//	printf("%d %d\n",u,st);
	ans[u] += mark[st];
	vis[u] = st;
	for(int i = head1[u];i;i = r[i].next)
	{
		int v = r[i].y;
		dfs1(v,st);
	}
}

int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	read(n),read(m),read(A),read(B);
	for(int i = 1;i <= n;i++) read(x[i]),read(y[i]);
	for(int i = 1;i <= m;i++)
	{
		int u,v,op;
		read(u),read(v),read(op);
		if(op == 1) add1(u,v);
		else add1(u,v),add1(v,u);
	}
	for(int i = 1;i <= n;i++)
	{
		if(!dfn[i]) dfs(i);
	}
	for(int u = 1;u <= n;u++)
	{
		for(int i = head[u];i;i = e[i].next)
		{
			int v = e[i].y;
			if(belong[u] != belong[v]) add2(belong[v],belong[u]);
		}
	}
	for(int u = 1;u <= n;u++)
	{
		if(x[u] == A) mark[belong[u]]++;
//		printf("%d %d\n",ans[2],mark[2]);
	}
	for(int i = 1;i <= cnt_;i++)
	{
		if(mark[i]) dfs1(i,i);
	}
	for(int i = 1;i <= n;i++)
	{
		if(x[i] == 0) print[++print_num].ans = ans[belong[i]],print[print_num].idx = y[i]; 
	}
	sort(print + 1,print + 1 + print_num);
	for(int i = 1;i <= print_num;i++) printf("%d\n",print[i].ans);
	return 0;
}

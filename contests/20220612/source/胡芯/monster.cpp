#include <bits/stdc++.h>
#pragma target ("avx")
#pragma optimize (1)
#pragma optimize (2)
#pragma optimize (3)
#pragma optimize ("inline")
#pragma optimize ("Ofast")
#define _rep(i,a,b) for(register int i(a);i^(b+1);i=-~i)
using namespace std;

int t;
int n,m;
char ch;
struct node
{
	int x;
	int y;
};
vector<node> q;
struct mon
{
	int id;
	int cnt;
};
mon r1[25];
mon r2[25];
bool cmp(mon a,mon b)
{
	return a.cnt>b.cnt;
}
int res=0;
void print()
{
	for (auto w:q)
	{
		if (w.x) printf(" %d %d\n",w.x,w.y);
	}
}
inline void work()
{
	bool find=true;
	while (find)
	{
		++res;
		find=false;
		int x,y;
		x=r1[1].id;
		y=r2[1].id;
		for (int i=0;i<q.size();++i)
		{
			if (q[i].x == -1) continue;
			if (q[i].x == x)
			{
				--r1[q[i].x].cnt;
				--r2[q[i].y].cnt;
				q[i].x=q[i].y=-1;
				find=true;
			}
		}
		for (int i=0;i<q.size();++i)
		{
			if (q[i].x == -1) continue;
			if (q[i].y == y)
			{
				--r1[q[i].x].cnt;
				--r2[q[i].y].cnt;
				q[i].x=-1,q[i].y=-1;
				find=true;
			}
		}
		sort (r1+1,r1+1+n,cmp);
		sort (r2+1,r2+1+m,cmp);
	}
}
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);
	
	scanf("%d",&t);
	while (t--)
	{
		q.clear();
		scanf("%d %d",&n,&m);
		_rep(i,1,n)
		{
			r1[i]=(mon)
			{
				i,0
			};
		}
		_rep(i,1,m)
		{
			r2[i]=(mon)
			{
				i,0
			};
		}
		_rep(i,1,n)
		{
			_rep(j,1,m)
			{
				cin>>ch;
				if (ch == '*')
				{
					++r1[i].cnt;
					++r2[j].cnt;
					q.push_back((node)
					{
						i,j
					});
				}
			}
		}
		sort (r1+1,r1+1+n,cmp);
		sort (r2+1,r2+1+m,cmp);
		res=0;
		work();
		printf("%d\n",res);
	}
	return 0;
}
/*
1
8 10
..........
..***..*.*
.*.......*
.*.......*
.*.......*
.....*****
..........
.........*

*/

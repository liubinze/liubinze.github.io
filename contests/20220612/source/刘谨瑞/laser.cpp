#include<stdio.h>
#include<algorithm>
#include<vector>
struct node{
	int v,nextn;
}b[2000005];
int bn,lastn[500005];
int T;
int n,m;
char s[505];
int a[505][505];
int u[505][505],d[505][505],l[505][505],r[505][505];
int id[505][505],idn;
bool f;
int dfs,dfsn[500005],low[500005],root[500005],Rt;
int t[500005],tn;
std::vector<int> v[500005];
void in(int u,int v)
{
//	printf("%d->%d\n",u,v);
	bn++;
	b[bn].v=v;
	b[bn].nextn=lastn[u];
	lastn[u]=bn;
}
void tarjan(int u)
{
	tn++;
	t[tn]=u;
	low[u]=dfsn[u]=++dfs;
	for(int i=lastn[u];i>0;i=b[i].nextn)
	{
		if(dfsn[b[i].v]==0)
		{
			tarjan(b[i].v);
			low[u]=std::min(low[u],low[b[i].v]);
		}
		else if(root[b[i].v]==0)
		{
			low[u]=std::min(low[u],dfsn[b[i].v]);
		}
	}
	if(low[u]==dfsn[u])
	{
		Rt++;
		while(true)
		{
			root[t[tn]]=Rt;
			v[Rt].push_back(t[tn]);
			if(t[tn]==u)
			{
				tn--;
				break;
			}
			tn--;
		}
	}
}
int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		idn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				id[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%s",&s);
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='.')
				{
					a[i][j]=0;
				}
				else if(s[j-1]=='S')
				{
					a[i][j]=1;
					idn++;
					id[i][j]=idn;
				}
				else
				{
					a[i][j]=2;
				}
			}
		}
//		printf("%d\n",idn);
		bn=0;
		dfs=0;
		Rt=0;
		tn=0;
		for(int i=1;i<=idn*2;i++)
		{
			lastn[i]=0;
			dfsn[i]=0;
			low[i]=0;
			root[i]=0;
			v[i].clear();
		}
		for(int i=0;i<=n+1;i++)
		{
			for(int j=0;j<=m+1;j++)
			{
				u[i][j]=d[i][j]=l[i][j]=r[i][j]=-1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					u[i][j]=u[i-1][j];
					l[i][j]=l[i][j-1];
				}
				else if(a[i][j]==1)
				{
					u[i][j]=i;
					l[i][j]=j;
				}
				else
				{
					u[i][j]=-1;
					l[i][j]=-1;
				}
			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==0)
				{
					d[i][j]=d[i+1][j];
					r[i][j]=r[i][j+1];
				}
				else if(a[i][j]==1)
				{
					d[i][j]=i;
					r[i][j]=j;
				}
				else
				{
					d[i][j]=-1;
					r[i][j]=-1;
				}
			}
		}
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%2d ",u[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%2d ",d[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%2d ",l[i][j]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				printf("%2d ",r[i][j]);
//			}
//			printf("\n");
//		}
		f=true;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0)
				{
					if(u[i][j]!=-1&&d[i][j]!=-1)
					{
						u[i][j]=d[i][j]=-1;
					}
					if(l[i][j]!=-1&&r[i][j]!=-1)
					{
						l[i][j]=r[i][j]=-1;
					}
					if(u[i][j]!=-1)
					{
						if(l[i][j]!=-1)
						{
							in(id[u[i][j]][j]+idn,id[i][l[i][j]]+idn);
							in(id[i][l[i][j]],id[u[i][j]][j]);
						}
						else if(r[i][j]!=-1)
						{
							in(id[u[i][j]][j]+idn,id[i][r[i][j]]+idn);
							in(id[i][r[i][j]],id[u[i][j]][j]);
						}
						else
						{
							in(id[u[i][j]][j]+idn,id[u[i][j]][j]);
						}
					}
					else if(d[i][j]!=-1)
					{
						if(l[i][j]!=-1)
						{
							in(id[d[i][j]][j]+idn,id[i][l[i][j]]+idn);
							in(id[i][l[i][j]],id[d[i][j]][j]);
						}
						else if(r[i][j]!=-1)
						{
							in(id[d[i][j]][j]+idn,id[i][r[i][j]]+idn);
							in(id[i][r[i][j]],id[d[i][j]][j]);
						}
						else
						{
							in(id[d[i][j]][j]+idn,id[d[i][j]][j]);
						}
					}
					else if(l[i][j]!=-1)
					{
						in(id[i][l[i][j]],id[i][l[i][j]]+idn);
					}
					else if(r[i][j]!=-1)
					{
						in(id[i][r[i][j]],id[i][r[i][j]]+idn);
					}
					else
					{
						f=false;
					}
				}
				else if(a[i][j]==1)
				{
					if(u[i-1][j]!=-1||d[i+1][j]!=-1)
					{
						in(id[i][j],id[i][j]+idn);//-
					}
					if(u[i-1][j]!=-1||d[i+1][j]!=-1)
					{
						in(id[i][j]+idn,id[i][j]);//|
					}
				}
			}
		}
		if(f)
		{
			for(int i=1;i<=idn*2;i++)
			{
				if(dfsn[i]==0)
				{
					tarjan(i);
				}
			}
//			for(int i=1;i<=idn*2;i++)
//			{
//				printf("%d %d %d %d\n",i,dfsn[i],low[i],root[i]);
//			}
//			for(int i=1;i<=Rt;i++)
//			{
//				for(int j=0;j<v[i].size();j++)
//				{
//					printf("%d ",v[i][j]);
//				}
//				printf("\n");
//			}
			for(int i=1;i<=idn;i++)
			{
				if(root[i]==root[i+idn])
				{
//					printf("%d %d %d %d\n",i,root[i],i+idn,root[i+idn]);
					f=false;
					break;
				}
			}
		}
		if(!f)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]==0)
					{
						printf(".");
					}
					else if(a[i][j]==2)
					{
						printf("#");
					}
					else
					{
						if(root[id[i][j]]>root[id[i][j]+idn])
						{
							printf("-");
						}
						else
						{
							printf("|");
						}
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
/*
| -> true
- -> false
1
5 50
.S#S..#S..#.S###S.##S.#S.##S.#S.#S.#S.#.S#.S#S.#S.
S.#..S#....S..#..S.......#S.................#..S..
..S#..S#.S.#...S##S.#S.#S..#S.#S.#S.#S.##S.#..S.##
##..S#..S#S.#...S....#.S#..S#S.#S.#.S#.S......#.S.
##.S##.S##.S#S.#.S#.S#S.#S..#.S#.S#S.##.S##S.###.S
1
2 7
#.S#.S#
S.....#
*/

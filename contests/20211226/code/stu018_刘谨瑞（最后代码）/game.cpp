#include<bits/stdc++.h>
using namespace std;
int t,n,m,bs,sx,sy,tx,ty,a[35][35],f[35],dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},no[4]={2,3,0,1};
char c,pr[4]={'U','R','D','L'};
bool flag;
void print()
{
	printf("YES\n");
	for(int i=0;i<bs;i++)
	{
		printf("%c",pr[f[i]]);
	}
	printf("\n");
}
void d(int x,int y,int s,int u)
{
	if(flag)
	{
		return;
	}
	a[x][y]=0;
	if(x==tx&&y==ty)
	{
		if(u==bs)
		{
			flag=true;
			print();
		}
	}
	else
	{
		int xx,yy;
		for(int i=0;i<4;i++)
		{
			if(flag)
			{
				return;
			}
			if(s!=no[i])
			{
				xx=x;
				yy=y;
				while(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]==0)
				{
					xx+=dx[i];
					yy+=dy[i];
				}
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
				{
					f[u]=i;
					d(xx,yy,i,u+1);
				}
			}
		}
	}
	a[x][y]=1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d\n",&n,&m);
		bs=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				c=getchar();
				if(c=='S')
				{
					sx=i;
					sy=j;
				}
				if(c=='T')
				{
					tx=i;
					ty=j;
				}
				if(c=='#')
				{
					a[i][j]=0;
				}
				else
				{
					a[i][j]=1;
					bs++;
				}
			}
			getchar();
		}
		flag=false;
		d(sx,sy,0,0);
		d(sx,sy,3,0);
		if(!flag)
		{
			printf("NO\n");
		}
	}
	return 0;
}

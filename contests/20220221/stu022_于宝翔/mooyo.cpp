#include<bits/stdc++.h>
using namespace std;

const int N=105,m=10,M=15;
const int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int n,k;
int a[N][M],del_len[M];
char s[M];
bool vis[N][M];
struct node
{
	int x,y;
};

int get(int x,int y,int col)
{
	int cnt=1;
	vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(!vis[xx][yy]&&a[xx][yy]==col)cnt+=get(xx,yy,col);
	}
	return cnt;
}

void del(int x,int y,int col)
{
	a[x][y]=0;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(a[xx][yy]==col)del(xx,yy,col);
	}
}

int main()
{
	freopen("mooyo.in","r",stdin);
	freopen("mooyo.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			a[i][j]=s[j]-'0';
		}
	}
	int cnt=1;
	while(cnt)
	{
		cnt=0;
		memset(vis,false,sizeof vis);
		memset(del_len,0,sizeof del_len);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==0||vis[i][j]==true)continue;
				int siz=get(i,j,a[i][j]);
				if(siz>=k)del(i,j,a[i][j]),cnt++;
			}
		for(int j=1;j<=m;j++)
			for(int i=n-1;i>=1;i--)
			{
				int id=i+1;
				for(;id<=n;id++)
					if(a[id][j])
					{
						id--;
						break;
					}
				if(id==i)continue;
				if(id>n)id=n;
				a[id][j]=a[i][j],a[i][j]=0;
			}
	}
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%d",a[i][j]);
	return 0;
}

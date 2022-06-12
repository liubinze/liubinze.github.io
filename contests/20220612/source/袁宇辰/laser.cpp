#include<bits/stdc++.h>
using namespace std;

int T;
int n,m;
char a[505][505];
bool f[505][505],f1[505][505],vis[505][505];

struct node
{
	int x,y;
};

vector<node>G;

void lr(int i,int j)
{
	int k=j-1;
	while(k>=1&&a[i][k]!='#')
	{
		vis[i][k]=1;
		k--;
	}
	k=j+1;
	while(k<=m&&a[i][k]!='#')
	{
		vis[i][k]=1;
		k++;
	}
}

void ud(int i,int j)
{
	int k=i-1;
	while(k>=1&&a[k][j]!='#')
	{
		vis[k][j]=1;
		k--;
	}
	k=i+1;
	while(k<=n&&a[k][j]!='#')
	{
		vis[k][j]=1;
		k++;
	}
}

bool ilr(int i,int j)
{
	int k=j-1;
	while(k>=1&&a[i][k]!='#')
	{
		if(!vis[i][k])return 1;
		k--;
	}
	k=j+1;
	while(k<=m&&a[i][k]!='#')
	{
		if(!vis[i][k])return 1;
		k++;
	}
	return 0;
}

bool iud(int i,int j)
{
	int k=i-1;
	while(k>=1&&a[k][j]!='#')
	{
		if(!vis[k][j])return 1;
		k--;
	}
	k=i+1;
	while(k<=n&&a[k][j]!='#')
	{
		if(!vis[k][j])return 1;
		k++;
	}
	return 0;
}

int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				f[i][j]=f1[i][j]=0;
				vis[i][j]=0;
			}
		G.clear();
		for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='S')
				{
					int k=i-1;
					while(k>=1&&a[k][j]!='#')
					{
						if(a[k][j]=='S')
						{
							f[i][j]=1;
							break;
						}
						k--;
					}
					k=i+1;
					while(k<=n&&a[k][j]!='#')
					{
						if(a[k][j]=='S')
						{
							f[i][j]=1;
							break;
						}
						k++;
					}
					k=j-1;
					while(k>=1&&a[i][k]!='#')
					{
						if(a[i][k]=='S')
						{
							f1[i][j]=1;
							break;
						}
						k--;
					}
					k=j+1;
					while(k<=m&&a[i][k]!='#')
					{
						if(a[i][k]=='S')
						{
							f1[i][j]=1;
							break;
						}
						k++;
					}
					if(f[i][j]==1&&f1[i][j]==1)
					{
						flag=1;
						cout<<"!"<<endl;
						break;
					}
					else if(f[i][j]==1)lr(i,j);
					else if(f1[i][j]==1)ud(i,j);
					else G.push_back({i,j});
				}
			}
			if(flag==1)break;
		}
		for(node u:G)
		{
			int i=u.x,j=u.y;
			if(ilr(i,j))
			{
				f[i][j]=1;
				lr(i,j);
			}
			else if(iud(i,j))
			{
				f1[i][j]=1;
				ud(i,j);
			}
			else f[i][j]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='.'&&!vis[i][j])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)break;
		}
		if(flag==1)printf("No\n");
		else
		{
			printf("Yes\n");
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(a[i][j]=='S')
					{
						if(f[i][j])printf("-");
						else printf("|");
					}
					else printf("%c",a[i][j]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

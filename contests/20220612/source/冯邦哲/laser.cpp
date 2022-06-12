#include<bits/stdc++.h>
using namespace std;
int n,m,mp[1000][1000],t,fx,fy,cnt1;
void check(int x,int y)
{
	for(int i=y+1;i<=m;i++)
	{
		if(mp[x][i]==1)
		{
			cnt1=cnt1-i+y;
			break;
		}
		if(mp[x][i]==2||mp[x][i]==3||mp[x][i]==4)
		{
			fx=1;
			break;
		}
	}
	for(int i=y-1;i>=1;i--)
	{
		if(mp[x][i]==1)
		{
			cnt1=cnt1-(y-i)-1;
			break;
		}
		if(mp[x][i]==2||mp[x][i]==3||mp[x][i]==4)
		{
			fx=1;
			break;
		}
	}
	for(int i=x+1;i<=n;i++)
	{
		if(mp[i][y]==1)
		{
			cnt1=cnt1-i+x;
			break;
		}
		if(mp[i][y]==2||mp[i][y]==3||mp[i][y]==4)
		{
			fy=1;
			break;
		}
	}
	for(int i=x-1;i>=1;i--)
	{
		if(mp[i][y]==1)
		{
			cnt1=cnt1-(x-1-i)-1;
			break;
		}
		if(mp[i][y]==2||mp[i][y]==3||mp[i][y]==4)
		{
			fy=1;
			break;
		}
	}
}
int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0,flag=0;
		cnt1=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			string s;
			cin>>s;
			for(int j=1;j<=m;j++)
			{
				if(s[j-1]=='.')mp[i][j]=0,cnt1++;
				if(s[j-1]=='#')mp[i][j]=1;
				if(s[j-1]=='S')mp[i][j]=2,cnt++;			
			}
		}
		int flag1=0;
		while(cnt!=0&&flag==0)
		{
			int last=cnt;
			for(int i=1;i<=n&&flag==0;i++)
			{
				for(int j=1;j<=m&&flag==0;j++)
				{
					if(mp[i][j]==2)
					{
						fx=fy=0;
						check(i,j);
						if(fx==1&&fy==1)
						{
							flag=1;
							break;
						}
						else
						{
							if(fx==1)mp[i][j]=3,cnt--;
							else if(fy==1)mp[i][j]=4,cnt--;
							else if(flag1==0)mp[i][j]=4,cnt--;
						}
					}
		 		}
			}
			if(last==cnt)flag1=1;
		}
		if(cnt1>0)
		{
			printf("NO\n");
			continue;
		}
		if(flag==1)printf("NO\n");
		else 
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(mp[i][j]==0)printf(".");
					else if(mp[i][j]==1)printf("#");
					else if(mp[i][j]==3)printf("|");
					else if(mp[i][j]==4)printf("-");
				}
				printf("\n");
			}
		}
	}
}

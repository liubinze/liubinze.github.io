#include<bits/stdc++.h>
int n,k,cnt,xx[4]={1,-1,0,0},yy[4]={0,0,1,-1};
char s[105][12],j[105];
bool u[105][12],u2[105][12];
void search(int x,int y,char c)
{
	cnt++;
	for(int a=0;a<4;a++)
	{
		int nx=x+xx[a],ny=y+yy[a];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=10)
		{
			if(u[nx][ny]==0&&s[nx][ny]==c)
			{
				u[nx][ny]=1;
				search(nx,ny,c);
			}
		}
	}
}
int main()
{
	freopen("mooyo.in","r",stdin);
	freopen("mooyo.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=10;b++) scanf(" %c",&s[a][b]);
	}
	while(1)
	{
		int h=0;
		memset(u2,0,sizeof(u2));
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=10;b++)
			{
				if(s[a][b]!='0'&&u2[a][b]==0)
				{
					memset(u,0,sizeof(u));
					cnt=0;
					u[a][b]=1;
					search(a,b,s[a][b]);
					if(cnt>=k)
					{
						h=1;
						for(int c=1;c<=n;c++)
						{
							for(int d=1;d<=10;d++)
							{
								if(u[c][d]==1) s[c][d]='0';
							}
						}
					}
					else
					{
						for(int c=1;c<=n;c++)
						{
							for(int d=1;d<=10;d++)
							{
								if(u[c][d]==1) u2[c][d]=1;
							}
						}
					}
				}
			}
	    }
		for(int a=1;a<=10;a++)
		{
			int m=0;
			for(int b=n;b>=1;b--)
			{
				if(s[b][a]!='0') j[++m]=s[b][a];
			}
			for(int b=n,c=1;b>=1&&c<=m;b--,c++)
			{
				s[b][a]=j[c];
			}
			for(int b=n-m;b>=1;b--)
			{
				s[b][a]='0';
			}
		}
		if(h==0) break;
	}
	for(int a=1;a<=n;a++)
	{
		for(int b=1;b<=10;b++) printf("%c",s[a][b]);
		printf("\n");
	}
}

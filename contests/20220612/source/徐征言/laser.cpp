#include<bits/stdc++.h>
using namespace std;
int x,y,T,n,m,M,ans;
char s[505][505];
void dfs(int x,int y)
{
	if(x>n)
	{
		bool ok=1;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
				if(s[a][b]=='.')
				{
				    bool check=0;
					for(int c=b-1;c>=1;c--)
					{
						if(s[a][c]=='-')
						{
							check=1;
							break;
						}
						else if(s[a][c]=='#') break;
					}
					for(int c=b+1;c<=m;c++)
					{
						if(s[a][c]=='-')
						{
							check=1;
							break;
						}
						else if(s[a][c]=='#') break;
					}
					for(int c=a-1;c>=1;c--)
					{
						if(s[c][b]=='|')
						{
							check=1;
							break;
						}
						else if(s[c][b]=='#') break;
					}
					for(int c=a+1;c<=n;c++)
					{
						if(s[c][b]=='|')
						{
							check=1;
							break;
						}
						else if(s[c][b]=='#') break;
					}
					if(check==0) ok=0;
				}
				else if(s[a][b]=='|'||s[a][b]=='-')
				{
					bool check=1;
					for(int c=b-1;c>=1;c--)
					{
						if(s[a][c]=='-')
						{
							check=0;
							break;
						}
						else if(s[a][c]=='#') break;
					}
					for(int c=b+1;c<=m;c++)
					{
						if(s[a][c]=='-')
						{
							check=0;
							break;
						}
						else if(s[a][c]=='#') break;
					}
					for(int c=a-1;c>=1;c--)
					{
						if(s[c][b]=='|')
						{
							check=0;
							break;
						}
						else if(s[c][b]=='#') break;
					}
					for(int c=a+1;c<=n;c++)
					{
						if(s[c][b]=='|')
						{
							check=0;
							break;
						}
						else if(s[c][b]=='#') break;
					}
					if(check==0) ok=0;
				}
				if(ok==0) break;
			}
			if(ok==0) break;
		}
		if(ok==1)
		{
			ans=1;
			printf("Yes\n");
			for(int a=1;a<=n;a++)
			{
				for(int b=1;b<=m;b++) printf("%c",s[a][b]);
				printf("\n");
			}
		}
		return;
	}
	if(s[x][y]=='S')
	{
		s[x][y]='|';
		if(y==m) dfs(x+1,1);
	    else dfs(x,y+1);
	    if(ans==1) return;
		s[x][y]='-';
		if(y==m) dfs(x+1,1);
	    else dfs(x,y+1);
	    if(ans==1) return;
		s[x][y]='S';
	}
	else if(y==m) dfs(x+1,1);
	else dfs(x,y+1);
	if(ans==1) return;
}
int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int a=1;a<=n;a++) scanf("%s",s[a]+1);
		int t=0;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
				if(s[a][b]=='S') t++;
			}
		}
		ans=0;
		if(t>=27)
		{
			printf("No\n");
			continue;
		}
		dfs(1,1);
		if(ans==0) printf("No\n");
	}
}

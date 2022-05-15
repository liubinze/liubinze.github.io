#include<bits/stdc++.h>
using namespace std;
int t,n,m,ans,h[35];
bool u[35][35];
char s[35][35],f[5];
void search(int x,int y,int dir)
{
	if(ans==1) return;
	u[x][y]=1;
	if(s[x][y]=='T')
	{
		bool check=1;
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++)
			{
				if(s[a][b]=='.'&&u[a][b]==0) check=0;
			}
		}
		if(check==1)
		{
			ans=1;
			printf("YES\n");
			for(int a=1;a<=h[0];a++) printf("%c",f[h[a]]);
			printf("\n");
		}
		u[x][y]=0;
		return;
	}
	for(int a=1;a<=4;a++)
	{
		if(a==1)
		{
			if(dir==3) continue;
			for(int b=x-1;b>=1;b--)
			{
				if((s[b][y]=='.'||s[b][y]=='T')&&u[b][y]==0)
				{
					h[++h[0]]=1;
					search(b,y,1);
					h[0]--;
					break;
				}
			}
		}
		if(a==2)
		{
			if(dir==4) continue;
			for(int b=y+1;b<=m;b++)
			{
				if((s[x][b]=='.'||s[x][b]=='T')&&u[x][b]==0)
				{
					h[++h[0]]=2;
					search(x,b,2);
					h[0]--;
					break;
				}
			}
		}
		if(a==3)
		{
			if(dir==1) continue;
			for(int b=x+1;b<=n;b++)
			{
				if((s[b][y]=='.'||s[b][y]=='T')&&u[b][y]==0)
				{
					h[++h[0]]=3;
					search(b,y,3);
					h[0]--;
					break;
				}
			}
		}
		if(a==4)
		{
			if(dir==2) continue;
			for(int b=y-1;b>=1;b--)
			{
				if((s[x][b]=='.'||s[x][b]=='T')&&u[x][b]==0)
				{
					h[++h[0]]=4;
					search(x,b,4);
					h[0]--;
					break;
				}
			}
		}
	}
	u[x][y]=0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	f[1]='U';
	f[2]='R';
	f[3]='D';
	f[4]='L';
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		memset(u,0,sizeof(u));
		scanf("%d%d",&n,&m);
		for(int a=1;a<=n;a++) scanf("%s",s[a]+1);
		for(int a=1;a<=n;a++)
		{
			for(int b=1;b<=m;b++) 
			{
				if(s[a][b]=='S') search(a,b,0);
			}
		}
		if(ans==0) printf("NO\n");
	}
}

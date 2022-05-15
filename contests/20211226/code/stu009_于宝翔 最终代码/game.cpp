#include<bits/stdc++.h>
using namespace std;

const int N=35;

bool mark[N][N],flag;
int t,n,m,cnt;
char s[N][N],ans[N];
struct node
{
	int x,y;
}start,end;

void dfs(node u,int len,int op,int cnt)
{
	/*if(ans[1]=='L'&&ans[2]=='U'&&ans[3]=='R'&&ans[4]=='D')
	{
		puts(" -------   ");
		cout<<cnt<<endl;
	}*/
	if(u.x==end.x&&u.y==end.y&&cnt<=0)
	{
		puts("YES");flag=true;
		for(int i=1;i<=len;i++)
		{
			printf("%c",ans[i]);
		}
		puts("");
		return;
	}
	int x=u.x,y=u.y;
	node temp;
	if(op!=2)
	{
		for(int i=x-1;i>=1;i--)
			if(mark[i][y])
			{
				mark[i][y]=false;
				temp.x=i,temp.y=y,ans[len+1]='U';
				dfs(temp,len+1,1,cnt-1);
				if(flag)return;
				mark[i][y]=true;
				break;
			}
	}
	if(op!=1)
	{
		for(int i=x+1;i<=n;i++)
			if(mark[i][y])
			{
				mark[i][y]=false;
				temp.x=i,temp.y=y,ans[len+1]='D';
				dfs(temp,len+1,2,cnt-1);
				if(flag)return;
				mark[i][y]=true;
				break;
			}
	}
	if(op!=4)
	{
		for(int j=y-1;j>=1;j--)
			if(mark[x][j])
			{
				mark[x][j]=false;
				temp.x=x,temp.y=j,ans[len+1]='L';
				dfs(temp,len+1,3,cnt-1);
				if(flag)return;
				mark[x][j]=true;
				break;
			}
	}	
	if(op!=3)
	{
		for(int j=y+1;j<=m;j++)
			if(mark[x][j])
			{
				mark[x][j]=false;
				temp.x=x,temp.y=j,ans[len+1]='R';
				dfs(temp,len+1,4,cnt-1);
				if(flag)return;
				mark[x][j]=true;
				break;
			}                                                                                                           
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		flag=false,cnt=0;
		memset(mark,false,sizeof mark);
		memset(ans,' ',sizeof ans);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='S')start.x=i,start.y=j;
				if(s[i][j]=='T')end.x=i,end.y=j;
				if(s[i][j]=='T'||s[i][j]=='.')mark[i][j]=true,cnt++;
			}
		}
		dfs(start,0,5,cnt);
		if(flag==false)
		{
			puts("NO");
		}
	}
	return 0;
}

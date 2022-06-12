#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int N=5;

int t,n,m,len;
bool is_finish;
char s[N][N];
char ans[N][N];
vector<pii> vt;

bool check()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]=='.')
			{
				bool flag=false;
				for(int k=j-1;k>=1;k--)
				{
					if(ans[i][k]=='#')break;
					else if(ans[i][k]=='-')
					{
						flag=true;
						break;
					}
				}
				if(flag==true)continue;
				for(int k=j+1;j<=m;j++)
				{
					if(ans[i][k]=='#')break;
					else if(ans[i][k]=='-')
					{
						flag=true;
						break;
					}
				}
				if(flag==true)continue;
				for(int k=i-1;k>=1;k--)
				{
					if(ans[k][j]=='#')break;
					else if(ans[k][j]=='|')
					{
						flag=true;
						break;
					}
				}
				if(flag==true)continue;
				for(int k=i+1;k<=n;k++)
				{
					if(ans[k][j]=='#')break;
					else if(ans[k][j]=='|')
					{
						flag=true;
						break;
					}
				}
				if(flag==false)return false;
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(ans[i][j]=='|')
			{
				for(int k=i-1;k>=1;k--)
				{
					if(ans[k][j]=='#')break;
					if(ans[k][j]=='|'||ans[k][j]=='-')return false;
				}
				for(int k=i+1;k<=n;k++)
				{
					if(ans[k][j]=='#')break;
					if(ans[k][j]=='|'||ans[k][j]=='-')return false;
				}
			}
			else if(ans[i][j]=='-')
			{
				for(int k=j-1;k>=1;k--)
				{
					if(ans[i][k]=='#')break;
					if(ans[i][k]=='|'||ans[i][k]=='-')return false;
				}
				for(int k=j+1;k<=m;k++)
				{
					if(ans[i][k]=='#')break;
					if(ans[i][k]=='|'||ans[i][k]=='-')return false;
				}
			}
	return true;
}

void solve()
{
	puts("Yes");
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=m;j++)
			printf("%c",ans[i][j]);
	is_finish=true;
}

void dfs(int k)
{
	if(is_finish)return;
	if(k==len)
	{
		if(check())
		{
			solve();
		}
		return;
	}
	int x=vt[k].first,y=vt[k].second;
	ans[x][y]='|';
	dfs(k+1);
	ans[x][y]='-';
	dfs(k+1);
}

int main()
{
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		vt.clear();
		is_finish=false;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				if(s[i][j]=='S')vt.push_back(make_pair(i,j));
				else ans[i][j]=s[i][j];
		}
		len=vt.size();
		dfs(0);
		if(is_finish==false)puts("No");
	}
	return 0;
}

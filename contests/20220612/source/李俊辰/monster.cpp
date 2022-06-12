#include<bits/stdc++.h>
using namespace std;
int m,n,link[100001],ey[100001],elast[100001],enext[100001],k;
bool vis[100001];
void add(int a,int b)
{
	k++;
	ey[k]=b;
	enext[k]=elast[a];
	elast[a]=k;
}
bool dfs(int u)
{
	for(int i=elast[u];i;i=enext[i])
	{
		int v=ey[i];
		if(vis[v]==true)
		continue;
		vis[v]=true;
		if(link[v]==-1||dfs(link[v]))
		{
			link[v]=u;
			return 1;
		}
	}
	return 0;
}
int init(){
	memset(link,-1,sizeof link);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		cnt+=dfs(n);
	}
	return cnt;
}
string a[26];
bool cun[26],cunn[26];
int main()
{
	freopen("monster.in","r",stdin);
	freopen("monster.out","w",stdout);		
	int t;
	cin>>t;
	while(t>0)
	{
		t--;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		cin>>a[i];
		for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		if(a[i][j]=='*')
		{
			cun[i]=true;
			cunn[j]=true;
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		if(cun[i]==true&&cunn[j]==true)
		{
			add(i,j+1+n*m);
			add(j+1+n*m,i);
		}		
		printf("%d\n",init());
	}
}
/*
1  
8 10  
..........  
..***..*.*  
.*.......*  
.*.......*  
.*.......*  
.....*****  
..........  
.........* 
*/


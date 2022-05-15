#include<bits/stdc++.h>
using namespace std;
string a[100];
bool zuoguo[100][100];
int  n,k,we[100][100];
int dfs_(int x,int y,int zhi)
{
	zhi++;
	int ans=zhi;
	if(a[x][y+1]==a[x][y])
	{
		if(zuoguo[x][y+1]==false)
		{
		zuoguo[x][y+1]=true;
		ans=max(ans,dfs_(x,y+1,zhi));
		zuoguo[x][y+1]=false;					
		}
	}
	if(a[x][y-1]==a[x][y])
	{
		if(zuoguo[x][y-1]==false)
		{
		zuoguo[x][y-1]=true;
		ans=max(ans,dfs_(x,y-1,zhi));
		zuoguo[x][y-1]=false;					
		}
	}	
	if(a[x+1][y]==a[x][y])
	{
		if(zuoguo[x+1][y]==false)
		{
		zuoguo[x+1][y]=true;
		ans=max(ans,dfs_(x+1,y,zhi));
		zuoguo[x+1][y]=false;					
		}
	}	
	if(a[x-1][y]==a[x][y])
	{
		if(zuoguo[x-1][y]==false)
		{
		zuoguo[x-1][y]=true;
		ans=max(ans,dfs_(x-1,y,zhi));
		zuoguo[x-1][y]=false;					
		}
	}	
	we[x][y]=ans;
	return ans;
}
int dfs_shan(int x,int y,int zhi)
{
	we[x][y]=0;
	a[x][y]='0';
	zhi++;
	int ans=zhi;
	if(a[x][y+1]==a[x][y])
	{
		if(zuoguo[x][y+1]==false)
		{
		zuoguo[x][y+1]=true;
		ans=max(ans,dfs_shan(x,y+1,zhi));
		zuoguo[x][y+1]=false;					
		}
	}
	if(a[x][y-1]==a[x][y])
	{
		if(zuoguo[x][y-1]==false)
		{
		zuoguo[x][y-1]=true;
		ans=max(ans,dfs_shan(x,y-1,zhi));
		zuoguo[x][y-1]=false;					
		}
	}	
	if(a[x+1][y]==a[x][y])
	{
		if(zuoguo[x+1][y]==false)
		{
		zuoguo[x+1][y]=true;
		ans=max(ans,dfs_shan(x+1,y,zhi));
		zuoguo[x+1][y]=false;					
		}
	}	
	if(a[x-1][y]==a[x][y])
	{
		if(zuoguo[x-1][y]==false)
		{
		zuoguo[x-1][y]=true;
		ans=max(ans,dfs_shan(x-1,y,zhi));
		zuoguo[x-1][y]=false;					
		}
	}	
	return ans;
}
int check()
{
	for(int i=2;i<=n;i++)
	for(int j=0;j<10;j++)
	{
		if(a[i-1][j]=='0')
		{
			a[i-1][j]=a[i][j];
			a[i][j]='0';
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=0;j<10;j++)
	{
		if(dfs_(i,j,0)>=k)
		{
			dfs_shan(i,j,0);
			return 0;
		}
	}
	return -1;
}
int main(){
	freopen("mooyo.in","r",stdin);
	freopen("mooyo.out","w",stdout);	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	while(check()==0)
	{
	}
	for(int i=1;i<=n;i++)
	cout<<a[i];
}

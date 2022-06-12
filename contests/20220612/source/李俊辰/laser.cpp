#include<bits/stdc++.h>
using namespace std;
struct qq{
	int x,y;
}qe[10001];
int r=0,zong=0;
bool we[100][101];
string ll[100];
		int n,m;
bool dfs(int x,char a[500])
{
	if(x==r+1)
	{
		
		for(int i=1;i<=r;i++)
		{
		if(a[i]=='|')
		{
		for(int j=qe[i].x+1;j<=n;j++)
		{
		if(ll[i][j]=='.')
		we[i][j]=true;		
		if(ll[i][j]=='#')
		break;
		if(ll[i][j]='S')
		return false;
		}
		for(int j=qe[i].x-1;j>=1;j--)
		{
		if(ll[i][j]=='.')
		we[i][j]=true;		
		if(ll[i][j]=='#')
		break;
		if(ll[i][j]='S')
		return false;	
		}			
		}
		else
		{
		for(int j=qe[i].y+1;j<m;j++)
		{
		if(ll[i][j]=='.')
		we[i][j]=true;		
		if(ll[i][j]=='#')
		break;
		if(ll[i][j]='S')
		return false;	
		}		
		for(int j=qe[i].y-1;j>=0;j--)
		{
		if(ll[i][j]=='.')
		we[i][j]=true;		
		if(ll[i][j]=='#')
		break;
		if(ll[i][j]='S')
		return false;	
		}			
		}	
		}
		for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
		if(we[i][j]==false&&ll[i][j]=='.')
		return false;
		printf("Yes\n");
		for(int i=1;i<=r;i++)
		ll[qe[i].x][qe[i].y]=a[i];		
		for(int i=1;i<=n;i++)
		{
		for(int j=0;j<m;j++)
		cout<<ll[i][j];			
		cout<<endl;
		}
		return true;
	}
	a[x]='|';
	if(dfs(x+1,a)==true)
	return true;
	a[x]='-';
	if(dfs(x+1,a)==true)
	return true;
	return false;
}
char wu[1001];
int main(){
	freopen("laser.in","r",stdin);
	freopen("laser.out","w",stdout);		
	int t;
	cin>>t;
	while(t>0)
	{
		printf("No\n");	
	}
}

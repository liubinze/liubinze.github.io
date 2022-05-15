#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[100005],nextn[100005][12],ans[100005];
bool flag;
void print(int x,int y)
{
	for(int i=1;i<=x&&i<=n-m;i++)
	{
		printf("%d ",ans[i]);
	}
	for(int i=y;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
void f(int x,int s)
{
	//printf("%d %d\n",x,s);
	if(flag)
	{
		return;
	}
	if(s==m)
	{
		flag=true;
		print(x-s,x+1);
		return;
	}
	for(int i=1;i<=k;i++)
	{
		if(flag)
		{
			return;
		}
		if(nextn[x][i]<=n+1&&s+nextn[x][i]-x-1<=m)
		{
			ans[x-s+1]=i;
			f(nextn[x][i],s+nextn[x][i]-x-1);
		}
	}
}
int main()
{
	freopen("removal.in","r",stdin); 
	freopen("removal.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&k)==3)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=10;i++)
		{
			nextn[n][i]=n+1;
			nextn[n+1][i]=n+2;
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=1;j<=k;j++)
			{
				nextn[i][j]=nextn[i+1][j];
			}
			nextn[i][a[i+1]]=i+1;
		}
		flag=false;
		f(0,0);
	}
	return 0;
}

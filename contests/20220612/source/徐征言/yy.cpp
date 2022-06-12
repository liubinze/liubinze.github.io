#include<bits/stdc++.h>
using namespace std;
int x,y,T,n,m,h[15],h2[15],ans;
bool vis[15],choose[15],choose2[15],e[15][15];
void search2(int k)
{
	if(k==n+1)
	{
		int tot=0;
		for(int a=1;a<=n;a++)
		{
			if(e[h[a]][h2[a]]==1) tot++;
			else if(a==1&&e[h[a]][h2[n]]==1) tot++;
			else if(e[h[a]][h2[a-1]]==1) tot++;
		}
		ans=min(ans,tot);
		return;
	}
	for(int a=1;a<=n;a++)
	{
		if(choose2[a]==0)
		{
			choose2[a]=1;
			h2[k]=a;
			search2(k+1);
			choose2[a]=0;
		}
	}
}
void search(int k)
{
	if(k==n+1)
	{
		memset(choose2,0,sizeof(choose2));
		search2(1);
		return;
	}
	for(int a=1;a<=n;a++)
	{
		if(choose[a]==0)
		{
			choose[a]=1;
			h[k]=a;
			search(k+1);
			choose[a]=0;
		}
	}
}
int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(e,0,sizeof(e));
		for(int a=1;a<=m;a++)
		{
			scanf("%d%d",&x,&y);
			e[x][y]=1;
		}
		ans=1e9;
		memset(choose,0,sizeof(choose));
		search(1);
		printf("%d\n",ans);
	}
}

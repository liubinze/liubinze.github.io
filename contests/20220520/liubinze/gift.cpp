#include<stdio.h>
bool mark[1001];
int n,e[1001][1001];
inline bool dfs(int ig,int st)
{
	if(st>n)
		return 1;
	if(st==ig)
		return dfs(ig,st+1);
	for(int i=1;i<=n&&e[st][i];i++)
		if(!mark[e[st][i]])
		{
			mark[e[st][i]]=1;
			if(dfs(ig,st+1))
				return mark[e[st][i]]=0,1;
			mark[e[st][i]]=0;
		}
	return 0;
}
int main()
{
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout);
	bool f=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++,f=0)
		for(int j=1;j<=n;j++)
			if(f)
				scanf("%*d");
			else
				scanf("%d",&e[i][j]),e[i][j]^i?0:f=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(e[i][j]==i)
			{
				printf("%d\n",i);
				break;
			}
			mark[e[i][j]]=1;
			if(dfs(i,1))
			{
				printf("%d\n",e[i][j]),mark[e[i][j]]=0;
				break;
			}
			mark[e[i][j]]=0;
		}
	return 0;
}

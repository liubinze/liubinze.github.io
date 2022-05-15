#include <bits/stdc++.h>
using namespace std;

int n,a[5005],ans,print[5005],print_[5005];

void dfs(int now,int tot,int maxn)
{
	if(now > n) return ;
	ans = max(ans,tot);
	dfs(now + 1,tot,maxn);
	if(a[now + 1] > maxn) 
	{
		dfs(now + 1,tot + 1,a[now + 1]);
	}
}

void FIND(int now,int tot,int maxn)
{
	if(now > n) return ;
	if(tot == ans)
	{
//	printf("%d %d %d\n",now,tot,maxn);
//	for(int i = 1;i <= ans;i++) printf("%d %d\n",print_[i],print[i]);
//	puts("");
		bool flag = false;
		for(int i = 1;i <= ans;i++)
		{
			if(print_[i] < print[i])
			{
//				printf("%d\n",i);
				flag = true;
				break;
			}
		}
//		printf("1");
		if(flag)
		{
//printf("!");
			for(int i = 1;i <= ans;i++)
			{
				print[i] = print_[i];
			}
		}
		return ;
	}
	FIND(now + 1,tot,maxn);
//	puts("");
//		if(now == 4 && tot == 1) printf("!");
	if(a[now + 1] > maxn) 
	{
//		if(now == 3 && tot == 0 && maxn == 0) printf("!");
		print_[tot + 1] = a[now + 1];
//	if(now == 3 && tot == 0 && maxn == 0)for(int i = 1;i <= ans;i++) printf("%d ",print_[i]);
		FIND(now + 1,tot + 1,a[now + 1]);
	}
}

int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	dfs(0,0,0);
	for(int i = 1;i <= ans;i++) print[i] = 0x3f3f3f3f;
	FIND(0,0,0);
	printf("%d\n",ans);
	for(int i = 1;i <= ans;i++) printf("%d ",print[i]);
	return 0;
}

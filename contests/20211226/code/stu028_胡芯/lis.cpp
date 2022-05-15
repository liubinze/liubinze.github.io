#include <bits/stdc++.h>
using namespace std;
int n;
int s[5001];
int res=-1,tp;
int a[5001];

int t[5001],ter;
void dfs(int len,int lst)
{
	for (int i=lst+1; i<=n; i++)
	{
		if (s[i]>t[len])
		{
			t[++len]=s[i];
			dfs(len,i);
			len--;
		}
	}
//	printf("%d\n ",len);
//	for (int i=1; i<=len; i++)
//	{
//		printf("%d ",t[i]);
//	}
//	printf("\n");
	if (len>res)
	{
		ter=0;
		res=len;
		for (int i=1; i<=len; i++)
		{
			ter+=t[i];
			a[i]=t[i];
		}
		tp=ter;
	}
	else if (len==res)
	{
		ter=0;
		for (int i=1; i<=len; i++)
		{
			ter+=t[i];
		}
		if (ter>tp)
		{
			for (int i=1; i<=len; i++)
			{
				a[i]=t[i];
			}
			tp=ter;
		}
	}
}
/*
4
2 1 2 3
*/
int main()
{
	freopen("lis.in","r",stdin);
	freopen("lis.out","w",stdout);
	scanf("%d",&n);
	if (n>1000) return 0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&s[i]);
	}
	for (int i=0; i<=n; i++)
	{
		dfs(0,i);
	}
	printf("%d\n",res);
	for (int i=1; i<=res; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

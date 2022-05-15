#include <bits/stdc++.h>
using namespace std;

int n,m,minq=0x7f7f7f7f;
int a[1001],s[1001];
void dfs(int k,int p)
{
	if (k>m)
	{
		int r=0;
		for (int i=1;i<=m;i++)
		{
			r=max(r,s[i]);
		}
		minq=min(minq,r);
	}
	else
	{
		for (int i=p+1;i<=n-(m-k);i++)
		{
			s[k]+=a[i];
			dfs(k+1,i);
		}
	}
}
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	if (n>1000) return 0;
	scanf("%d %d",&n,&m);
	for (register int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	dfs(1,0);
	printf("%d",minq);
	return 0;
}

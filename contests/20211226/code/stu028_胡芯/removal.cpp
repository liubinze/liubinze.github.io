#include <bits/stdc++.h>
using namespace std;
int n,m,k;
struct node
{
	int s;
	int ls;
}a[1000001];
bool cmp(node s,node t)
{
	return s.s>t.s;
}
bool wdo(node x,node y)
{
	return x.ls<y.ls;
}
int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while (scanf("%d %d %d",&n,&m,&k)==3)
	{
		for (int i=1; i<=n; i++)
		{
			scanf("%d",&a[i].s);
			a[i].ls=i;
		}
		sort (a+1,a+1+n,cmp);
		for (int i=1;i<=m;i++)
		{
			a[i].ls=n+1;
		}
		sort (a+1,a+1+n,wdo);
		for (int i=1;i<=n-m;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
	return 0;
}

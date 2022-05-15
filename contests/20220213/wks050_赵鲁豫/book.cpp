#include<iostream>
using namespace std;
int n,m,ans=-99999999;
int a[200005];
int main()
{
	freopen("book.in","r",stdin);
	freopen("book.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		ans=max(ans,a[i]);
	}
	printf("%d",ans);
}


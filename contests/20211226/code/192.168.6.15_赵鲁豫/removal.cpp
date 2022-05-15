#include<iostream>
using namespace std;
int n,m,k;
struct node{
	int x,next;
}a[100005];
int f[100005][15],l[100005];
int main()
{
	freopen("removal.in","r",stdin);
	freopen("removal.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&k))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i].x);
		}
		for(int i=n;i>=1;i--)
		{
			a[i].next=l[a[i].x];
			l[a[i].x]=i;
		}
		int num=0;
		while(m)
		{
			int cnt=10,gg=0;
			for(int i=num+1;i<=m+num&&i<=n;i++)
			{
				if(a[i].x==cnt)
				{
					gg++;
				}
				if(a[i].x<cnt)
				{
					cnt=a[i].x;
					gg=1;
				}
			}
			m=gg;
			num+=m;
			for(int i=1;i<=gg;i++)
			{
				printf("%d ",cnt);
			}
		}
		printf("\n");
	}
}

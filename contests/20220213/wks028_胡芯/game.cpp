#include <bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n,k;
int path[71];
ll fc[53];
int ksm(int n);
void d();

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	d();
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d %d",&n,&k);
//	printf("For %d %d\n ",n,k);
		if (k==0)
		{
			printf("%d\n",0);
			continue;
		}
		if (fc[lower_bound(fc+1,fc+1+32,k)-fc]!=k)
		{
			printf("NO\n");
			continue;
		}
//	printf(" ");;
		printf("YES\n");
//	printf(" ");
		for (int i=1; i<=k; i<<=1)
		{
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
int ksm(int n)
{
	int a=2;
	int res=1;
	while (n)
	{
		if (n&1)
		{
			res=res*a;
		}
		a*=a;
		n>>=1;
	}
	return res;
}
void d()
{
	fc[0]=0;
	for (register int i=1; i<=33; i++)
	{
		fc[i]=fc[i-1]+ksm(i-1);
	}
}

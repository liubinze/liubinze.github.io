#include <bits/stdc++.h>
using namespace std;
const int N=1.0E5+1;

int n,m,c,u=0;
int t[N];
int tk[N];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d %d %d",&n,&m,&c);
	for (int i=1; i<=n; i++)
	{
		scanf("%d",&t[i]);
	}
	sort (t+1,t+1+n);
	int lek=-1;
	for (int i=1; i<n; i++)
	{
		lek=max(lek,t[i+1]-t[i]);
	}
//	puts("");
	int maxx=-1;
	int st,ed;
	for (int i=1,j=0; i<=n; i++)
	{
//		printf("\t %d %d\n",i,j);
		if (j==0)
		{
			st=i;
			j=1;
			continue;
		}
		if (i==1)
		{
			st=1;
			j++;
			continue;
		}
		if ((t[i]-t[i-1]) == lek && u<m-1)
		{
			u++;
//			printf("P %d %d\n",i,j);
			j=1;
			ed=i-1;
			maxx=max(t[ed]-t[st],maxx);
//			printf("%d %d (%d)\n",st,ed,i);
		}
		else
		{
			j++;
//			printf("G %d %d\n",i,j);
			if (j==c)
			{
				u++;
				j=0;
				ed=i;
				maxx=max(t[ed]-t[st],maxx);
//				printf("%d %d (%d)\n",st,ed,i);
			}
		}
	}
	printf("%d",maxx);
	return 0;
}
/*
6 3 2
1 1 10 14 4 3


6 3 2
1 4 5 6 10 15
*/

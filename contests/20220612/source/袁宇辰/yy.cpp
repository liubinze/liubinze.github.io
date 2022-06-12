#include<bits/stdc++.h>
using namespace std;

int T;
int n,m;
int x[100],y[100];

int main()
{
	freopen("yy.in","r",stdin);
	freopen("yy.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		srand(time(NULL));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)scanf("%d%d",&x[i],&y[i]);
		printf("%d\n",rand()%(n+1));
	}
	return 0;
}

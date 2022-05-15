#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int n,m,c;
int a[N],mac[N];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%d%d%d",&n,&m,&c);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	if(m==n)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(i+c-1>n)mac[i]=a[n]-a[i];
		else mac[i]=a[i+c-1]-a[i];
	}
	if(m*c==n)
	{	
		int Max=0;
		for(int i=1;i<=n;i+=c)Max=max(Max,mac[i]);
		printf("%d\n",Max);
		return 0;
	}
	
}

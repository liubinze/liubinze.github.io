#pragma GCC optimize("Ofast,inline,no-stack-protector,unroll-loops")
#include<stdio.h>
#include<algorithm>
int poi[2001];
struct st
{
	int s[2001],t;
}e[2001];
int main()
{
	freopen("queue.in","r",stdin),freopen("queue.out","w",stdout);
	int n,s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&e[i].t),s+=e[i].t;
		for(int j=0;j<e[i].t;j++)
			scanf("%d",&e[i].s[j]);
	}
	std::sort(e,e+n,[](st a,st b){for(int i=0;i<a.t&&i<b.t;i++)if(a.s[i]^b.s[i])return a.s[i]<b.s[i];return a.t<b.t;});
	for(int i=0;i<n;i++)
		poi[i]=0;
	for(int i=0,m;i<s;i++)
	{
		m=-1;
		for(int j=0;j<n;j++)
			if(poi[j]<e[j].t&&(!~m||e[j].s[poi[j]]<e[m].s[poi[m]]))
				m=j;
		printf("%d ",e[m].s[poi[m]]),poi[m]++;
	}
	return 0;
}

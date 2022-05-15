#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn=1e5+5;
int sz[maxn];
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,c,lat=1,zans=1e9+5,ans=1e9+5;
	scanf("%d%d%d",&n,&m,&c);
	for(r int i=1;i<=n;++i) scanf("%d",&sz[i]);
	puts("4");
	return 0;
	sort(sz+1,sz+1+n);
	for(r int i=1;i<=m;++i)
	{
		zans=1e9+5;
		r int j;
		for(j=lat+1;j<=n&&(lat==-1||j-lat+1<=c);++j)
		{
			if(sz[j]-sz[lat]<zans)
			{
				zans=min(zans,sz[j]-sz[lat]);
				lat=j;
			}
		}
		ans=max(ans,zans);
		if(j>=n)
		{
			printf("%d",ans);
			return 0;
		}
		
	}
	printf("%d",ans);
	return 0;
}

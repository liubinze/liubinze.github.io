#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn=200005;
char sz[maxn];
int mark[maxn];
inline int read()
{
	r int rt=0,f=1;
	r char gt=getchar();
	while(gt>'9'||gt<'0')
	{
		if(gt=='-') f=-1;
		gt=getchar();
	}
	while(gt<='9'&&gt>='0')
	{
		rt=(rt<<1)+(rt<<3)+(gt^48);
		gt=getchar();
	}
	return f*rt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	r int n=read(),m=read(),l,ri,pl=0,zn,jl;
	zn=n;
	r char ask;
	getchar();
	for(r int i=1;i<=n;++i) sz[i]=getchar();
	while(m--)
	{
		l=read(),ri=read(),ask=getchar();
		getchar();
		if(l>zn) continue;
		for(r int i=1;i<=n;++i)
		{
			if(mark[i]==1) continue;
			++pl;
			if(pl==l)
			{
				jl=i;
				break;
			}
		}
		pl=0;
		for(r int i=jl;i<=n;++i)
		{
			if(pl>ri-l) break;
			if(mark[i]==1) continue;
			
			++pl;
			if(sz[i]==ask) 
			{
				mark[i]=1;
				--zn;
				continue;
			}
		}
		pl=0;
		jl=n+1;
	}
	for(r int i=1;i<=n;++i) if(mark[i]==1) continue;else putchar(sz[i]);
	exit(0);
}

#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn = 1e5 + 5 ;
int q[maxn];
priority_queue<int> wait;

struct node
{
	int a,t,mark,nows;
}sz[maxn];

inline bool cmp(node a,node b)
{
	return a.a<=b.a;
}

signed main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	r int n,ans=0,now=1,lat=1,is=1,dq,mj,ss;
	

	scanf("%d",&n);
	for(r int i=1;i<=n;++i)
	{
		scanf("%d%d",&sz[i].a,&sz[i].t);
		sz[i].mark=n-i+1;
	}
	
	sort(sz+1,sz+1+n,cmp);
	for(r int i=1;i<=n;++i) q[sz[i].mark]=i;
	dq=1;
	mj=1;
	for(r int i=2;i<=n;++i)
	{
		r int k,zmj;
		for(k=mj;k<=n&&sz[k].a<=sz[dq].a+sz[dq].t;++k)
		{
			wait.push(sz[k].mark);
			zmj=k;
		}
		mj=zmj;
		dq=q[wait.top()];
		ans=max(ans,sz[lat].a+sz[lat].t-sz[dq].a+1);
		ss=lat;
		lat=dq;
		if(wait.empty()) 
		{
			continue;
		}
		else wait.pop();
	}
	
	printf("%d",ans);
	exit(0);
}


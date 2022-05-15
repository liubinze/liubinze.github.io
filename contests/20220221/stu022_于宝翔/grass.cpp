#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,M=1e7+5;
const int maxn=2e9+5;

int n,tot,root;
int level[N];
struct node
{
	int a,t,lev;
}a[N];
struct SegmentTree
{
	struct Tree
	{
		int lson,rson,dat;
	}t[M];
	
	int build()
	{
		tot++;
		t[tot].lson=t[tot].rson=t[tot].dat=0;
		return tot;
	}
	
	void update(int p,int l,int r,int x,int d)
	{
		if(l==r){t[p].dat=max(t[p].dat,d);return;}
		int mid=l+r>>1;
		if(x<=mid)
		{
			if(!t[p].lson)t[p].lson=build();
			update(t[p].lson,l,mid,x,d);
		}
		else
		{
			if(!t[p].rson)t[p].rson=build();
			update(t[p].rson,mid+1,r,x,d);
		}
		t[p].dat=max(t[t[p].lson].dat,t[t[p].rson].dat);
	}
	
	void del(int p,int l,int r,int x)
	{
		if(l==r){t[p].dat=0;return;}
		int mid=l+r>>1;
		if(x<=mid&&t[p].lson)del(t[p].lson,l,mid,x);
		if(x>mid&&t[p].rson)del(t[p].rson,mid+1,r,x);
		t[p].dat=max(t[t[p].lson].dat,t[t[p].rson].dat);
	}
	
	int query(int p,int l,int r,int x,int y)
	{
		if(x<=l&&r<=y)return t[p].dat;
		int mid=l+r>>1,val=0;
		if(x<=mid&&t[p].lson)val=max(val,query(t[p].lson,l,mid,x,y));
		if(y>mid&&t[p].rson)val=max(val,query(t[p].rson,mid+1,r,x,y));
		return val;
	}
	
}seg;

bool cmp(node x,node y)
{
	if(x.a==y.a)return x.lev>y.lev;
	else return x.a<y.a;
}

int main()
{
	freopen("grass.in","r",stdin);
	freopen("grass.out","w",stdout);
	root=seg.build();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].t);
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i].lev=i;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		level[a[i].lev]=i;
		seg.update(root,1,maxn,a[i].a,a[i].lev);
	}
	int now_time=a[1].a+a[1].t,ans=0;
	seg.del(1,1,maxn,a[1].lev);
	for(int i=2;i<=n;i++)
	{
		int pos=seg.query(1,1,maxn,1,now_time);
		pos=level[pos];
		ans=max(ans,now_time-a[pos].a);
		now_time=now_time+a[pos].t;
		seg.del(1,1,maxn,a[pos].lev);
	}
	printf("%d",ans-1);
	return 0;
}

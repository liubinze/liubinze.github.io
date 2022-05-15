#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,x,y;
}a[100005];
struct Tree{
	int l,r,maxn,addn;
}dp[400005];
int n;
int c[200005],findn[100005];
bool cmp(node x,node y)
{
	return x.a==y.a?x.b<y.b:x.a>y.a;
}
void build(int p,int l,int r)
{
	dp[p].l=l;
	dp[p].r=r;
	if(l==r)
	{
		findn[l]=p;
	}
	else
	{
		int mid=l+r>>1;
		build(p<<1,l,mid);
		build(p<<1|1,mid+1,r);
	}
}
int Get(int p,int l,int r)
{
	if(dp[p].l==l&&dp[p].r==r)
	{
		return dp[p].maxn+dp[p].addn;
	}
	else
	{
		int mid=dp[p].l+dp[p].r>>1;
		if(l<=mid&&r<=mid)
		{
			return Get(p<<1,l,r);
		}
		else if(l>mid&&r>mid)
		{
			return Get(p<<1|1,l,r);
		}
		else
		{
			return max(Get(p<<1,l,mid),Get(p<<1|1,mid+1,r));
		}
	}
}
void Add(int p,int l,int r,int d)
{
	if(dp[p].l==l&&dp[p].r==r)
	{
		dp[p].addn+=d;
	}
	else
	{
		int mid=dp[p].l+dp[p].r>>1;
		if(l<=mid&&r<=mid)
		{
			Add(p<<1,l,r,d);
		}
		else if(l>mid&&r>mid)
		{
			Add(p<<1|1,l,r,d);
		}
		else
		{
			Add(p<<1,l,mid,d);
			Add(p<<1|1,mid+1,r,d);
		}
		dp[p].maxn=max(dp[p<<1].maxn+dp[p<<1].addn,dp[p<<1|1].maxn+dp[p<<1|1].addn);
	}
}
void Set(int p,int x,int d)
{
	if(dp[p].l==dp[p].r)
	{
		dp[p<<1].addn+=dp[p].addn;
		dp[p<<1|1].addn+=dp[p].addn;
		dp[p].maxn+=dp[p].addn;
		dp[p].addn=0;
		dp[p].maxn=max(dp[p].maxn,d);
	}
	else
	{
		dp[p<<1].addn+=dp[p].addn;
		dp[p<<1|1].addn+=dp[p].addn;
		dp[p].addn=0;
		int mid=dp[p].l+dp[p].r>>1;
		if(x<=mid)
		{
			Set(p<<1,x,d);
		}
		else if(x>mid)
		{
			Set(p<<1|1,x,d);
		}
		dp[p].maxn=max(dp[p<<1].maxn+dp[p<<1].addn,dp[p<<1|1].maxn+dp[p<<1|1].addn);
	}
}
int main()
{
	scanf("%d",&n);
	build(1,0,2*n+1);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&a[i].a,&a[i].b,&a[i].x,&a[i].y);
		c[2*i-1]=a[i].a;
		c[2*i]=a[i].b;
	}
	sort(c+1,c+n*2+1);
	for(int i=1;i<=n;i++)
	{
		a[i].a=lower_bound(c+1,c+n+1,a[i].a)-c;
		a[i].b=lower_bound(c+1,c+n+1,a[i].b)-c;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		Set(1,a[i].b,Get(1,a[i].b,2*n+1)+a[i].x);
		Add(1,0,a[i].b-1,a[i].x);
		Add(1,a[i].b+1,2*n+1,a[i].y);
	}
	printf("%d\n",Get(1,0,2*n+1));
	return 0;
}

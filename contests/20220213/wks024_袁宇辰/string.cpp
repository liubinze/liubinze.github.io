#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,m;
char s[N];

struct node
{
	int l,r,len;
	int sum[80];
}tree[N<<1];

void pushup(int p)
{
	for(int i=1;i<=75;i++)
	{
		tree[p].sum[i]=tree[p<<1].sum[i]+tree[p<<1|1].sum[i];
	}
	tree[p].len=tree[p<<1].len+tree[p<<1|1].len;
}

void pushdown(int p,char c)
{
	if(tree[p].l==tree[p].r)
	{
		tree[p].len=0;
		tree[p].sum[c-47]=0;
		return;
	}
	if(tree[p<<1].sum[c-47])
	{
		tree[p<<1].len-=tree[p<<1].sum[c-47];
		tree[p<<1].sum[c-47]=0;
		pushdown(p<<1,c);
	}
	if(tree[p<<1|1].sum[c-47])
	{
		tree[p<<1|1].len-=tree[p<<1|1].sum[c-47];
		tree[p<<1|1].sum[c-47]=0;
		pushdown(p<<1|1,c);
	}
}
void build(int p,int x,int y)
{
	tree[p].l=x,tree[p].r=y;
	if(x==y)
	{
		tree[p].sum[s[x]-47]=1;
		tree[p].len=1;
		return;
	}
	int mid=(x+y)>>1;
	build(p<<1,x,mid);
	build(p<<1|1,mid+1,y);
	pushup(p);
}

void modify(int p,int x,int y,char c)
{
	if(x==1&&y>=tree[p].len)
	{
		tree[p].len-=tree[p].sum[c-47];
		tree[p].sum[c-47]=0;
		pushdown(p,c);
		return;
	}
	if(!tree[p].sum[c-47])return;
	if(x<=tree[p<<1].len)
	{
		if(y<=tree[p<<1].len)
		{
			if(tree[p<<1].sum[c-47])
				modify(p<<1,x,y,c);
		}
		else
		{
			int t=tree[p<<1].len;
			if(tree[p<<1].sum[c-47])modify(p<<1,x,t,c);
			if(tree[p<<1|1].sum[c-47])modify(p<<1|1,1,y-t,c);
		}
	}
	else
	{
		if(tree[p<<1|1].sum[c-47])modify(p<<1|1,x-tree[p<<1].len,y-tree[p<<1].len,c);
	}
	pushup(p);
}

void print(int p)
{
	if(tree[p].l==tree[p].r)
	{
		if(tree[p].sum[s[tree[p].l]-47])printf("%c",s[tree[p].l]);
		return;
	}
	if(tree[p].len)
	{
		if(tree[p<<1].len)print(p<<1);
		if(tree[p<<1|1].len)print(p<<1|1);
	}
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	build(1,1,n);
	while(m--)
	{
		int L,R;
		char c;
		scanf("%d%d",&L,&R);
		if(L>tree[1].len)continue;
		if(R>tree[1].len)R=tree[1].len;
		cin>>c;
		modify(1,L,R,c);
	}
	print(1);
	return 0;
}
